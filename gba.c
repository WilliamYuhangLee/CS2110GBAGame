#include "gba.h"

volatile unsigned short *videoBuffer = (volatile unsigned short *)0x6000000;
u32 vBlankCounter = 0;

void waitForVBlank(void) {
    // Write a while loop that loops until we're NOT in vBlank anymore:
    // (This prevents counting one VBlank more than once if your app is too fast)
    while (SCANLINECOUNTER >= 160);
    // Write a while loop that keeps going until we're in vBlank:
    while (SCANLINECOUNTER < 160);
    // Finally, increment the vBlank counter:
    vBlankCounter++;
}

void setPixel(int x, int y, u16 color) {
    videoBuffer[OFFSET(y, x, WIDTH)] = color;
}

void drawRectDMA(int x, int y, int width, int height, volatile u16 color) {
    for (int i = 0; i < height; i++) {
        DMA[DMA_CHANNEL_3].src = &color;
        DMA[DMA_CHANNEL_3].dst = &videoBuffer[OFFSET(y + i, x, WIDTH)];
        DMA[DMA_CHANNEL_3].cnt = width | DMA_SOURCE_FIXED | DMA_DESTINATION_INCREMENT | DMA_ON;
    }
}

void drawFullScreenImageDMA(u16 *image) {
    DMA[DMA_CHANNEL_3].src = image;
    DMA[DMA_CHANNEL_3].dst = videoBuffer;
    DMA[DMA_CHANNEL_3].cnt = (WIDTH * HEIGHT) | DMA_SOURCE_INCREMENT | DMA_DESTINATION_INCREMENT | DMA_ON;
}

void drawImageDMA(int x, int y, int width, int height, const u16 *image) {
    for (int i = 0; i < height; i++) {
        DMA[DMA_CHANNEL_3].src = &image[OFFSET(i, 0, width)];
        DMA[DMA_CHANNEL_3].dst = &videoBuffer[OFFSET(y + i, x, WIDTH)];
        DMA[DMA_CHANNEL_3].cnt = width | DMA_SOURCE_INCREMENT | DMA_DESTINATION_INCREMENT | DMA_ON;
    }
}

void fillScreenDMA(volatile u16 color) {
    DMA[DMA_CHANNEL_3].src = &color;
    DMA[DMA_CHANNEL_3].dst = videoBuffer;
    DMA[DMA_CHANNEL_3].cnt = (WIDTH * HEIGHT) | DMA_SOURCE_FIXED | DMA_DESTINATION_INCREMENT | DMA_ON;
}

void drawChar(int col, int row, char ch, u16 color) {
    for(int r = 0; r<8; r++) {
        for(int c=0; c<6; c++) {
            if(fontdata_6x8[OFFSET(r, c, 6) + ch*48]) {
                DMA[3].src = &color;
                DMA[3].dst = &videoBuffer[OFFSET(row + r, col + c, WIDTH)];
                DMA[3].cnt = 1 | DMA_ON;
            }
        }
    }
}

void drawString(int col, int row, char *str, u16 color) {
    while(*str) {
        drawChar(col, row, *str++, color);
        col += 6;
    }
}

void drawCenteredString(int x, int y, int width, int height, char *str, u16 color) {
    u32 len = 0;
    char *strCpy = str;
    while (*strCpy) {
        len++;
        strCpy++;
    }

    u32 strWidth = 6 * len;
    u32 strHeight = 8;

    int col = x + ((width - strWidth) >> 1);
    int row = y + ((height - strHeight) >> 1);
    drawString(col, row, str, color);
}

void toggleSpriteMode(u16 sprites_dimension_type) {
    REG_DISPCNT ^= (OBJ_ENABLE | sprites_dimension_type);
}

void importSpritePalette(const u16* sprite_palette, u16 length) {
    DMA[3].src = sprite_palette;
    DMA[3].dst = SPRITE_PALETTE;
    DMA[3].cnt = (u32) length | DMA_ON;
}
void importSpriteData(const u16* sprites, u16 length) {
    DMA[3].src = sprites;
    DMA[3].dst = &CHARBLOCKBASE[5];
    DMA[3].cnt = (u32) length | DMA_ON;
}
