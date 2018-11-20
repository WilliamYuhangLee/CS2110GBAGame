/*
 * Exported with nin10kit v1.7
 * Invocation command was nin10kit --mode=sprites --bpp=8 --for_bitmap --transparent=000000 sprites GT.png Garbage.png TRASH_NORMAL.png TRASH_INFLATED.png JAVA.png 
 * Time-stamp: Tuesday 11/20/2018, 20:11:57
 * 
 * Image Information
 * -----------------
 * GT.png 32@32
 * Garbage.png 32@32
 * TRASH_NORMAL.png 32@32
 * TRASH_INFLATED.png 32@32
 * JAVA.png 16@16
 * Transparent color: (0, 0, 0)
 * 
 * All bug reports / feature requests are to be filed here https://github.com/TricksterGuy/nin10kit/issues
 */

#ifndef SPRITES_H
#define SPRITES_H

#define SPRITES_PALETTE_TYPE (1 << 13)
#define SPRITES_DIMENSION_TYPE (1 << 6)

extern const unsigned short sprites_palette[239];
#define SPRITES_PALETTE_SIZE 478
#define SPRITES_PALETTE_LENGTH 239

extern const unsigned short sprites[2176];
#define SPRITES_SIZE 4352
#define SPRITES_LENGTH 2176

#define GT_PALETTE_ID (0 << 12)
#define GT_SPRITE_SHAPE (0 << 14)
#define GT_SPRITE_SIZE (2 << 14)
#define GT_ID 512

#define GARBAGE_PALETTE_ID (0 << 12)
#define GARBAGE_SPRITE_SHAPE (0 << 14)
#define GARBAGE_SPRITE_SIZE (2 << 14)
#define GARBAGE_ID 544

#define TRASH_NORMAL_PALETTE_ID (0 << 12)
#define TRASH_NORMAL_SPRITE_SHAPE (0 << 14)
#define TRASH_NORMAL_SPRITE_SIZE (2 << 14)
#define TRASH_NORMAL_ID 576

#define TRASH_INFLATED_PALETTE_ID (0 << 12)
#define TRASH_INFLATED_SPRITE_SHAPE (0 << 14)
#define TRASH_INFLATED_SPRITE_SIZE (2 << 14)
#define TRASH_INFLATED_ID 608

#define JAVA_PALETTE_ID (0 << 12)
#define JAVA_SPRITE_SHAPE (0 << 14)
#define JAVA_SPRITE_SIZE (1 << 14)
#define JAVA_ID 640

#endif

