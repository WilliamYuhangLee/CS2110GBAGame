#include "logic.h"
#include <stdlib.h>
#include "graphics.h"
#include "gba.h"

static int __qran_seed= 42;
static int qran(void) {
    __qran_seed= 1664525*__qran_seed+1013904223;
    return (__qran_seed>>16) & 0x7FFF;
}

int randint(int min, int max) {
    return (qran()*(max-min)>>15)+min;
}

void initializeAppState(AppState* appState) {
    // TA-TODO: Initialize everything that's part of this AppState struct here.
    // Suppose the struct contains random values, make sure everything gets
    // the value it should have when the app begins.
    __qran_seed = vBlankCounter;

    appState->garbageCollected = 0;
    appState->life = 3;
    appState->newItemTimer = 0;

    // Initialize trashCan
    TrashCan* trashCan = malloc(sizeof(TrashCan));
    if(trashCan == NULL) {
        return;
    }
    trashCan->x = 1;
    trashCan->y = 54;
    trashCan->width = 32;
    trashCan->height = 32;
    trashCan->inflateTimer = 0;

    appState->trashCan = trashCan;

    // Initialize items
    for (int i = 0; i < ITEM_NUMBER; i++) {
        appState->items[i] = NULL;
    }
    appState->lastID = ITEM_NUMBER - 1;
}

// TA-TODO: Add any process functions for sub-elements of your app here.
// For example, for a snake game, you could have a processSnake function
// or a createRandomFood function or a processFoods function.
//
// e.g.:
// static Snake processSnake(Snake* currentSnake);
// static void generateRandomFoods(AppState* currentAppState, AppState* nextAppState);

static void randomlyMakeItems(u32* newItemTimer, u8* lastID, Item* items[]) {
    if (*newItemTimer < MIN_INTERVAL) {
        (*newItemTimer)++;
        return;
    }
    if (*newItemTimer >= MAX_INTERVAL || *newItemTimer >= (u32) randint(MIN_INTERVAL, MAX_INTERVAL)) {
        *newItemTimer = 0;
        *lastID = (u8) ((*lastID + 1) % ITEM_NUMBER);
        Item* item = malloc(sizeof(Item));
        if (item == NULL) {
            return;
        }
        item->width = 32;
        item->height = 32;
        item->x = WIDTH;
        item->y = (short) randint(0, HEIGHT - 20 - item->height);
        item->id = *lastID;
        item->isGarbage = randint(0, 100) <= GARBAGE_CHANCE;
        items[*lastID] = item;
    } else {
        (*newItemTimer)++;
    }
}

static void shiftItems(u32 keysPressedNow, TrashCan* trashCan, Item* items[]) {
    short vMove = (bool) KEY_DOWN(BUTTON_DOWN, keysPressedNow) - (bool) KEY_DOWN(BUTTON_UP, keysPressedNow);
    trashCan->y += vMove * BASE_VERTICAL_SHIFT_SPEED * 2;

    // hard edges
    if (trashCan->y < 0) {
        trashCan->y = 0;
    } else if (trashCan->y > (short) (HEIGHT - 20 - trashCan->height)) {
        trashCan->y = (short) (HEIGHT - 20 - trashCan->height);
    }

    // teleport between two edges
//    if (trashCan->y < (short) (- trashCan->height)) {
//        trashCan->y = (short) (HEIGHT - 20 - trashCan->height);
//    } else if (trashCan->y > (short) (HEIGHT - 20 - trashCan->height)) {
//        trashCan->y = (short) (- trashCan->height);
//    }

    short hMove = (bool) KEY_DOWN(BUTTON_RIGHT, keysPressedNow) - (bool) KEY_DOWN(BUTTON_LEFT, keysPressedNow);
    trashCan->x += hMove * BASE_HORIZONTAL_SHIFT_SPEED * 2;
    if (trashCan->x < 0) {
        trashCan->x = 0;
    } else if (trashCan->x > (short) (WIDTH - trashCan->width)) {
        trashCan->x = (short) (WIDTH - trashCan->width);
    }

    for(int i = 0; i < ITEM_NUMBER; i++) {
        if (items[i] != NULL) {
            items[i]->x -= BASE_HORIZONTAL_SHIFT_SPEED;
            if (items[i]->x < 0) {
                free(items[i]);
                items[i] = NULL;
            }
        }
    }
}

static void handleCollision(TrashCan* trashCan, Item* items[], u32* garbageCollected, u8* life) {
    if (trashCan->inflateTimer) {
        trashCan->inflateTimer--;
    }
    for (int i = 0; i < ITEM_NUMBER; i++) {
        if (items[i] != NULL) {
            if (items[i]->x <= trashCan->x + (short) trashCan->width
                    && items[i]->x + (short) items[i]->width >= trashCan->x) {
                if (items[i]->y <= trashCan->y + (short) trashCan->height
                        && items[i]->y + (short) items[i]->height >= trashCan->y) {
                    if (items[i]->isGarbage) {
                        (*garbageCollected)++;
                    } else {
                        (*life)--;
                    }
                    trashCan->inflateTimer = INFLATE_SPAN;
                    free(items[i]);
                    items[i] = NULL;
                }
            }
        }
    }
}

// This function processes your current app state and returns the new (i.e. next)
// state of your application.
AppState processAppState(AppState *currentAppState, u32 keysPressedBefore, u32 keysPressedNow) {
    /* TA-TODO: Do all of your app processing here. This function gets called
     * every frame.
     *
     * To check for key presses, use the KEY_JUST_PRESSED macro for cases where
     * you want to detect each key press once, or the KEY_DOWN macro for checking
     * if a button is still down.
     *
     * To count time, suppose that the GameBoy runs at a fixed FPS (60fps) and
     * that VBlank is processed once per frame. Use the vBlankCounter variable
     * and the modulus % operator to do things once every (n) frames. Note that
     * you want to process button every frame regardless (otherwise you will
     * miss inputs.)
     *
     * Do not do any drawing here.
     *
     * TA-TODO: VERY IMPORTANT! READ THIS PART.
     * You need to perform all calculations on the currentAppState passed to you,
     * and perform all state updates on the nextAppState state which we define below
     * and return at the end of the function. YOU SHOULD NOT MODIFY THE CURRENTSTATE.
     * Modifying the currentAppState will mean the undraw function will not be able
     * to undraw it later.
     */

    AppState nextAppState = *currentAppState;

    handleCollision(nextAppState.trashCan, nextAppState.items, &(nextAppState.garbageCollected), &(nextAppState.life));

    shiftItems(keysPressedNow, nextAppState.trashCan, nextAppState.items);

    randomlyMakeItems(&(nextAppState.newItemTimer), &(nextAppState.lastID), nextAppState.items);

    UNUSED(keysPressedBefore);

    return nextAppState;
}
