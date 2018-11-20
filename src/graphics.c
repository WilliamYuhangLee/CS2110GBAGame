#include "graphics.h"
#include "gba.h"
#include "logic.h"

#include <stdlib.h>
#include <stdio.h>

#include "images/sprites.h"
#include "images/wrong.h"

OAMEntry shadow[128];

void setUpGraphics(void) {

    // Set Mode 3.
    REG_DISPCNT = MODE3 | BG2_ENABLE;

    // Enable sprites
    toggleSpriteMode(SPRITES_DIMENSION_TYPE);

    // Import sprite palette
    importSpritePalette(sprites_palette, SPRITES_PALETTE_LENGTH);

    // Import sprite data
    importSpriteData(sprites, SPRITES_LENGTH);

    // Hide all sprites at first
    for (int i = 0; i < 128; i++) {
        shadow[i].attr0 = ATTR0_HIDDEN;
        shadow[i].attr1 = 0;
        shadow[i].attr2 = 0;
    }
}

static void drawTrashCan(TrashCan* trashCan) {
    OAMEntry* trashCanSprite = &shadow[ITEM_NUMBER + 1];
    if (trashCan->inflateTimer) {
        trashCanSprite->attr0 = (trashCan->y & 0xFF) | SPRITES_PALETTE_TYPE | TRASH_INFLATED_SPRITE_SHAPE;
        trashCanSprite->attr1 = (trashCan->x & 0x1FF) | TRASH_INFLATED_SPRITE_SIZE;
        trashCanSprite->attr2 = TRASH_INFLATED_ID | PRIORITY(0) | TRASH_INFLATED_PALETTE_ID;
    } else {
        trashCanSprite->attr0 = (trashCan->y & 0xFF) | SPRITES_PALETTE_TYPE | TRASH_NORMAL_SPRITE_SHAPE;
        trashCanSprite->attr1 = (trashCan->x & 0x1FF) | TRASH_NORMAL_SPRITE_SIZE;
        trashCanSprite->attr2 = TRASH_NORMAL_ID | PRIORITY(0) | TRASH_NORMAL_PALETTE_ID;
    }
}

static void drawItem(Item* item) {
    OAMEntry* itemSprite = &shadow[item->id];
    switch (item->type) {
        case GARBAGE:
            itemSprite->attr0 = (item->y & 0xFF) | SPRITES_PALETTE_TYPE | GARBAGE_SPRITE_SHAPE;
            itemSprite->attr1 = (item->x & 0x1FF) | GARBAGE_SPRITE_SIZE;
            itemSprite->attr2 = GARBAGE_ID | PRIORITY(0) | GARBAGE_PALETTE_ID;
            break;
        case JEWELRY:
            itemSprite->attr0 = (item->y & 0xFF) | SPRITES_PALETTE_TYPE | GT_SPRITE_SHAPE;
            itemSprite->attr1 = (item->x & 0x1FF) | GT_SPRITE_SIZE;
            itemSprite->attr2 = GT_ID | PRIORITY(0) | GT_PALETTE_ID;
            break;
        case BONUS:
            itemSprite->attr0 = (item->y & 0xFF) | SPRITES_PALETTE_TYPE | JAVA_SPRITE_SHAPE;
            itemSprite->attr1 = (item->x & 0x1FF) | JAVA_SPRITE_SIZE;
            itemSprite->attr2 = JAVA_ID | PRIORITY(0) | JAVA_PALETTE_ID;
            break;
    }
}

void fullDrawScore(int x, int y, u32 score, u16 color) {
    char str[12];
    sprintf(str, "%d", score);
    drawString(x, y, str, color);
}

static void undrawScore(u32 currentScore) {
    if (currentScore) {
        u8 count = 0;
        while (currentScore) {
            count++;
            currentScore /= 10;
        }
        drawRectDMA(120, 146, count * 6, 8, BLACK);
    }
}

static void drawLife(short nextLife) {
    switch (nextLife) {
        case 3:
            drawImageDMA(186, 142, 16, 16, wrong);
        case 2:
            drawImageDMA(204, 142, 16, 16, wrong);
        case 1:
            drawImageDMA(222, 142, 16, 16, wrong);
        case 0:
        default:
            return;
    }
}

static void undrawLife(void) {
    drawRectDMA(186, 142, 53, 16, BLACK);
}

// This function will be used to draw everything about the app
// including the background and whatnot.
void fullDrawAppState(AppState *state) {
    // Draw sprites
    drawTrashCan(state->trashCan);

    // Draw interface
    volatile u16 color = WHITE;
    DMA[3].src = &color;
    DMA[3].dst = videoBuffer;
    DMA[3].cnt = (u32) 140 * WIDTH | DMA_SOURCE_FIXED | DMA_ON;

    color = BLACK;
    DMA[3].src = &color;
    DMA[3].dst = &videoBuffer[OFFSET(140, 0, WIDTH)];
    DMA[3].cnt = (u32) 20 * WIDTH | DMA_SOURCE_FIXED | DMA_ON;

    drawString(6, 146, "Garbage collected:", WHITE);
    fullDrawScore(120, 146, state->garbageCollected, WHITE);

    drawImageDMA(186, 142, 16, 16, wrong);
    drawImageDMA(204, 142, 16, 16, wrong);
    drawImageDMA(222, 142, 16, 16, wrong);
}

void undrawSprite(u8 id) {
    shadow[id].attr0 = ATTR0_HIDDEN;
}

void undrawAllSprites(void) {
    for (int i = 0; i < 128; i++) {
        undrawSprite(i);
    }
}

// This function will be used to undraw (i.e. erase) things that might
// move in a frame. E.g. in a Snake game, erase the Snake, the food & the score.
void undrawAppState(AppState *currentState) {
    undrawScore(currentState->garbageCollected);
    undrawLife();
}

// This function will be used to draw things that might have moved in a frame.
// For example, in a Snake game, draw the snake, the food, the score.
void drawAppState(AppState *state) {
    drawTrashCan(state->trashCan);
    for (int i = 0; i < ITEM_NUMBER; i++) {
        if (state->items[i] != NULL) {
            drawItem(state->items[i]);
        } else {
            undrawSprite(i);
        }
    }
    fullDrawScore(120, 146, state->garbageCollected, WHITE);
    drawLife(state->life);
}

void updateOAM(void) {
    DMA[3].src = shadow;
    DMA[3].dst = OAMMEM;
    DMA[3].cnt = (u32) 128 * 4 | DMA_ON;
}
