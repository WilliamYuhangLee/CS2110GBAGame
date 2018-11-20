#ifndef GRAPHICS_SEEN
#define GRAPHICS_SEEN

#include "logic.h"

extern OAMEntry shadow[128];

#define SHADOW(item) ((*shadow)[(item)->id])
#define TRASHCANSPRITE ((*shadow)[ITEM_NUMBER + 10])

// Initialize graphics environment including set display mode and importing sprites
void setUpGraphics(void);

// This function will be used to draw everything about the state of your app
// including the background and whatnot.
void fullDrawAppState(AppState *state);

void fullDrawScore(int x, int y, u32 score, u16 color);

void undrawSprite(u8 id);

void undrawAllSprites(void);

// This function will be used to undraw (i.e. erase) things that might
// move in a frame. E.g. in a Snake game, erase the Snake, the food & the score.
void undrawAppState(AppState* currentState, AppState* nextState);

// This function will be used to draw things that might have moved in a frame.
// For example, in a Snake game, draw the snake, the food, the score.
void drawAppState(AppState *state);

// If you have anything else you need accessible from outside the graphics.c
// file, you can add them here. You likely won't.

void updateOAM(void);

#endif
