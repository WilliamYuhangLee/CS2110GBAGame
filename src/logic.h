#ifndef LOGIC_SEEN
#define LOGIC_SEEN

#include "gba.h"
#include <stdbool.h>

#define TICK_PER_SECOND 60
#define MIN_INTERVAL (TICK_PER_SECOND / 2) // change the last part only
#define MAX_INTERVAL (TICK_PER_SECOND * 3 / 2) // change the last part only
#define GARBAGE_CHANCE 70 // out of 100
#define BASE_HORIZONTAL_SHIFT_SPEED 1 // in pixels
#define BASE_VERTICAL_SHIFT_SPEED 1 // in pixels
#define ITEM_NUMBER 32 // size of the items array
#define INFLATE_SPAN 25 // change the last part only
#define STRATEGY_NUMBER 10

typedef struct {
    short x;
    short y;
    short width;
    short height;
    u8 inflateTimer;
} TrashCan;

typedef enum {
   GARBAGE,
   JEWELRY,
   BONUS
} Type;

typedef struct {
    short x;
    short y;
    short width;
    short height;
    short xv;
    Type type;
    u8 id;
} Item;

typedef struct {
    u32 garbageCollected;
    short life;
    TrashCan* trashCan;
    Item* items[ITEM_NUMBER];
    u8 lastID;
    short newItemTimer;
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
