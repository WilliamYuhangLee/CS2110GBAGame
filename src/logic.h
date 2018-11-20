#ifndef LOGIC_SEEN
#define LOGIC_SEEN

#include "gba.h"
#include <stdbool.h>

#define TICK_PER_SECOND 60
#define MIN_INTERVAL (TICK_PER_SECOND * 1) // change the last part only
#define MAX_INTERVAL (TICK_PER_SECOND * 2) // change the last part only
#define GARBAGE_CHANCE 70 // out of 100
#define BASE_HORIZONTAL_SHIFT_SPEED 1 // in pixels
#define BASE_VERTICAL_SHIFT_SPEED 1 // in pixels
#define ITEM_NUMBER 16 // size of the items array
#define INFLATE_SPAN 25 // change the last part only

/*
* TA-TODO: Add any additional structs that you need for your app.
*
* For example, for a Snake game, one could be:
*
* typedef struct {
*   int heading;
*   int length;
*   int x;
*   int y;
* } Snake;
*
*/

typedef struct {
    short x;
    short y;
    u32 width;
    u32 height;
    u32 inflateTimer;
} TrashCan;

typedef struct {
    short x;
    short y;
    u32 width;
    u32 height;
    bool isGarbage;
    u8 id;
} Item;

typedef struct {
    // Store whether or not the game is over in this member:
    u32 garbageCollected;
    u8 life;
    TrashCan* trashCan;
    Item* items[ITEM_NUMBER];
    u8 lastID;
    u32 newItemTimer;

    /*
    * TA-TODO: Add any logical elements you need to keep track of in your app.
    *
    * For example, for a Snake game, those could be:
    *
    * Snake snake;
    * Food foods[10];
    * int points;
    *
    */

} AppState;

// This function can initialize an unused AppState struct.
void initializeAppState(AppState *appState);

// This function will be used to process app frames.
AppState processAppState(AppState *currentAppState, u32 keysPressedBefore, u32 keysPressedNow);

/**
 * Generates a pseudo-random number between min and max, inclusive.
 *
 * @param  min bottom end of range.
 * @param  max top end of range.
 * @return     random number in the given range.
 */
int randint(int min, int max);

#endif
