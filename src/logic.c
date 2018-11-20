#include "logic.h"
#include <stdlib.h>
#include "graphics.h"
#include "gba.h"

int randint(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// store strategy timers
static short strategies[STRATEGY_NUMBER];

void initializeAppState(AppState* appState) {
    srand(vBlankCounter);

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

    // Initialize strategy timers
    for (int i = 0; i < STRATEGY_NUMBER; i++) {
        strategies[i] = 0;
    }
}

static void generateStrategy(int strategy, short* newItemTimer, u8* lastID, Item* items[]) {
    while(strategies[strategy] && strategy < STRATEGY_NUMBER) {
        strategy++;
    }
    if (strategy >= STRATEGY_NUMBER) {strategy = 0;}
    *newItemTimer = 0;
    Item* item;
    short temp;
    switch (strategy) {
        default:
        case 0:
            if ((item = malloc(sizeof(Item))) == NULL) return;
            *lastID = (u8) ((*lastID + 1) % ITEM_NUMBER);
            item->width = 32;
            item->height = 32;
            item->x = WIDTH;
            item->y = (short) randint(0, HEIGHT - 20 - item->height);
            item->xv = (short) BASE_HORIZONTAL_SHIFT_SPEED;
            item->id = *lastID;
            item->isGarbage = randint(0, 99) < GARBAGE_CHANCE;
            items[*lastID] = item;
            break;
        case 1:
        case 2:
            if ((item = malloc(sizeof(Item))) == NULL) return;
            *lastID = (u8) ((*lastID + 1) % ITEM_NUMBER);
            item->width = 32;
            item->height = 32;
            item->x = WIDTH;
            item->y = (short) randint(0, HEIGHT - 20 - item->height);
            item->xv = (short) BASE_HORIZONTAL_SHIFT_SPEED * 2;
            item->id = *lastID;
            item->isGarbage = randint(0, 99) < GARBAGE_CHANCE;
            items[*lastID] = item;
            break;
        case 3:
            if ((item = malloc(sizeof(Item))) == NULL) return;
            *lastID = (u8) ((*lastID + 1) % ITEM_NUMBER);
            item->width = 32;
            item->height = 32;
            item->x = WIDTH;
            item->y = (short) randint(0, HEIGHT - 20 - item->height);
            item->xv = (short) BASE_HORIZONTAL_SHIFT_SPEED * 3;
            item->id = *lastID;
            item->isGarbage = randint(0, 99) < GARBAGE_CHANCE;
            items[*lastID] = item;
            *newItemTimer = -TICK_PER_SECOND;
            break;
        case 4:
            temp = (short) randint(0, HEIGHT - 20 - 32);
            for (int i = 0; i < 4; i++) {
                if ((item = malloc(sizeof(Item))) == NULL) return;
                *lastID = (u8) ((*lastID + 1) % ITEM_NUMBER);
                item->width = 32;
                item->height = 32;
                item->x = (short) (WIDTH + i * item->width);
                item->y = temp;
                item->xv = BASE_HORIZONTAL_SHIFT_SPEED * 2;
                item->id = *lastID;
                item->isGarbage = true;
                items[*lastID] = item;
            }
            if ((item = malloc(sizeof(Item))) == NULL) return;
            *lastID = (u8) ((*lastID + 1) % ITEM_NUMBER);
            item->width = 32;
            item->height = 32;
            item->x = (short) (WIDTH + 4 * item->width);
            item->y = temp;
            item->xv = BASE_HORIZONTAL_SHIFT_SPEED * 2;
            item->id = *lastID;
            item->isGarbage = false;
            items[*lastID] = item;
            strategies[3] = TICK_PER_SECOND * 3;
            strategies[5] = TICK_PER_SECOND * 3;
            break;
        case 5:
            for (int i = 0; i < 2; i++) {
                if ((item = malloc(sizeof(Item))) == NULL) return;
                *lastID = (u8) ((*lastID + 1) % ITEM_NUMBER);
                item->width = 32;
                item->height = 32;
                item->x = WIDTH;
                item->y = (short) (38 + (i * 32));
                item->xv = BASE_HORIZONTAL_SHIFT_SPEED * 2;
                item->id = *lastID;
                item->isGarbage = false;
                items[*lastID] = item;
            }
            strategies[4] = TICK_PER_SECOND * 3;
            strategies[3] = TICK_PER_SECOND * 3;
            break;
        case 6:
            for (int i = 1; i < 4; i++) {
                if ((item = malloc(sizeof(Item))) == NULL) return;
                *lastID = (u8) ((*lastID + 1) % ITEM_NUMBER);
                item->width = 32;
                item->height = 32;
                item->x = WIDTH + (i - 1) * 20;
                item->y = (short) (HEIGHT - 20 - (i * 32));
                item->xv = BASE_HORIZONTAL_SHIFT_SPEED * 2;
                item->id = *lastID;
                item->isGarbage = false;
                items[*lastID] = item;
            }
            *newItemTimer = -TICK_PER_SECOND * 2;
            strategies[8] = TICK_PER_SECOND * 3;
            break;
        case 7:
            for (int i = 0; i < 3; i++) {
                if ((item = malloc(sizeof(Item))) == NULL) return;
                *lastID = (u8) ((*lastID + 1) % ITEM_NUMBER);
                item->width = 32;
                item->height = 32;
                item->x = WIDTH + i * 20;
                item->y = (short) (i * 32);
                item->xv = BASE_HORIZONTAL_SHIFT_SPEED * 2;
                item->id = *lastID;
                item->isGarbage = false;
                items[*lastID] = item;
            }
            *newItemTimer = -TICK_PER_SECOND * 2;
            strategies[7] = TICK_PER_SECOND * 3;
            break;
        case 8:
            for (int i = 1; i < 4; i++) {
                if ((item = malloc(sizeof(Item))) == NULL) return;
                *lastID = (u8) ((*lastID + 1) % ITEM_NUMBER);
                item->width = 32;
                item->height = 32;
                item->x = WIDTH;
                item->y = (short) (HEIGHT - 20 - (i * 32));
                item->xv = BASE_HORIZONTAL_SHIFT_SPEED;
                item->id = *lastID;
                item->isGarbage = false;
                items[*lastID] = item;
            }
            *newItemTimer = -TICK_PER_SECOND;
            strategies[6] = TICK_PER_SECOND * 3;
            break;
        case 9:
            for (int i = 0; i < 3; i++) {
                if ((item = malloc(sizeof(Item))) == NULL) return;
                *lastID = (u8) ((*lastID + 1) % ITEM_NUMBER);
                item->width = 32;
                item->height = 32;
                item->x = WIDTH;
                item->y = (short) (i * 32);
                item->xv = BASE_HORIZONTAL_SHIFT_SPEED;
                item->id = *lastID;
                item->isGarbage = false;
                items[*lastID] = item;
            }
            *newItemTimer = -TICK_PER_SECOND;
            strategies[7] = TICK_PER_SECOND * 3;
            break;
    }
    strategies[strategy] = TICK_PER_SECOND * 3;
}

static void randomlyMakeItems(short* newItemTimer, u8* lastID, Item* items[]) {
    for (int i = 0; i < STRATEGY_NUMBER; i++) {
        if (strategies[i]) {
            strategies[i]--;
        }
    }
    if (*newItemTimer < MIN_INTERVAL) {
        (*newItemTimer)++;
        return;
    }
    if (*newItemTimer >= MAX_INTERVAL || *newItemTimer >= randint(MIN_INTERVAL, MAX_INTERVAL)) {
        generateStrategy(randint(0, STRATEGY_NUMBER - 1), newItemTimer, lastID, items);
    } else {
        (*newItemTimer)++;
    }
}

static void shiftItems(u32 keysPressedNow, TrashCan* trashCan, Item* items[]) {
    short vMove = (bool) KEY_DOWN(BUTTON_DOWN, keysPressedNow) - (bool) KEY_DOWN(BUTTON_UP, keysPressedNow);
    trashCan->y += vMove * BASE_VERTICAL_SHIFT_SPEED * 2;

    // hard edges
    if (trashCan->y < - trashCan->height / 2) {
        trashCan->y = (short) (- trashCan->height / 2);
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
            items[i]->x -= items[i]->xv;
            if (items[i]->x + items[i]->width < 0) {
                free(items[i]);
                items[i] = NULL;
            }
        }
    }
}

static void handleCollision(TrashCan* trashCan, Item* items[], u32* garbageCollected, short* life) {
    if (trashCan->inflateTimer) {
        trashCan->inflateTimer--;
    }
    for (int i = 0; i < ITEM_NUMBER; i++) {
        if (items[i] != NULL) {
            if (items[i]->x <= trashCan->x + trashCan->width
                    && items[i]->x + items[i]->width >= trashCan->x) {
                if (items[i]->y <= trashCan->y + trashCan->height
                        && items[i]->y + items[i]->height >= trashCan->y) {
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
    AppState nextAppState = *currentAppState;

    handleCollision(nextAppState.trashCan, nextAppState.items, &(nextAppState.garbageCollected), &(nextAppState.life));

    shiftItems(keysPressedNow, nextAppState.trashCan, nextAppState.items);

    randomlyMakeItems(&(nextAppState.newItemTimer), &(nextAppState.lastID), nextAppState.items);

    UNUSED(keysPressedBefore);

    return nextAppState;
}
