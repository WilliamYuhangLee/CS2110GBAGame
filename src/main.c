#include "gba.h"
#include "logic.h"
#include "graphics.h"

#include "images/background.h"
#include "images/sprites.h"

#include <stdio.h>
#include <stdlib.h>

// AppState enum definition
typedef enum {
    START,
    START_NO_DRAW,
    INSTRUCTION,
    INSTRUCTION_NO_DRAW,
    CONTROL,
    CONTROL_NO_DRAW,
    APP_INIT,
    APP,
    APP_EXIT,
    APP_EXIT_NO_DRAW,
} GBAState;

int main(void) {

    // Initialize graphics
    setUpGraphics();

    // Initialize GBA state
    GBAState state = START;

    // We store the "previous" and "current" game states.
    AppState currentAppState, nextAppState;

    // We store the current and previous values of the button input.
    u32 previousButtons = BUTTONS;
    u32 currentButtons;

    while(1) {
        // Load the current state of the buttons
        currentButtons = BUTTONS;

        switch(state) {
            case START:
                // Wait for VBlank
                waitForVBlank();

                drawImageDMA(0, 0, 240, 160, BACKGROUND_START_SCREEN);

                state = START_NO_DRAW;
                break;
            case START_NO_DRAW:
                // Start the app by switching the state to INSTRUCTION.
                if (KEY_JUST_PRESSED(BUTTON_START, currentButtons, previousButtons)) {
                    state = INSTRUCTION;
                }
                break;
            case INSTRUCTION:
                // Wait for VBlank
                waitForVBlank();

                drawImageDMA(0, 0, 240, 160, BACKGROUND_INSTRUCTION_SCREEN);

                state = INSTRUCTION_NO_DRAW;
                break;
            case INSTRUCTION_NO_DRAW:
                // Start the app by switching the state to CONTROL.
                if (KEY_JUST_PRESSED(BUTTON_SELECT, currentButtons, previousButtons)) {
                    state = START;
                } else if (KEY_JUST_PRESSED(BUTTON_START, currentButtons, previousButtons)) {
                    state = CONTROL;
                }
                break;
            case CONTROL:
                // Wait for VBlank
                waitForVBlank();

                drawImageDMA(0, 0, 240, 160, BACKGROUND_CONTROL_SCREEN);

                state = CONTROL_NO_DRAW;
                break;
            case CONTROL_NO_DRAW:
                // Start the app by switching the state to APP_INIT.
                if (KEY_JUST_PRESSED(BUTTON_SELECT, currentButtons, previousButtons)) {
                    state = START;
                } else if (KEY_JUST_PRESSED(BUTTON_START, currentButtons, previousButtons)) {
                    state = APP_INIT;
                }
                break;
            case APP_INIT:
                // Initialize the app. Switch to the APP state.
                initializeAppState(&currentAppState);

                // Draw the initial state of the app
                fullDrawAppState(&currentAppState);

                updateOAM();

                state = APP;
                break;
            case APP:
                // Process the app for one frame, store the next state
                nextAppState = processAppState(&currentAppState, previousButtons, currentButtons);

                // Wait for VBlank before we do any drawing.
                waitForVBlank();

                // Undraw the previous state
                undrawAppState(&currentAppState);

                if (KEY_JUST_PRESSED(BUTTON_SELECT, currentButtons, previousButtons)) {
                    state = START;
                    undrawAllSprites();
                    updateOAM();
                    break;
                }
                // Check if the app is exiting. If it is, then go to the exit state.
                if (nextAppState.life <= 0) {
                    state = APP_EXIT;
                    undrawAllSprites();
                    updateOAM();
                    break;
                }

                // Draw the current state
                drawAppState(&nextAppState);

                // Update OAM
                updateOAM();

                // Now set the current state as the next state for the next iter.
                currentAppState = nextAppState;

                break;
            case APP_EXIT:
                // Wait for VBlank
                waitForVBlank();

                drawImageDMA(0, 0, 240, 160, BACKGROUND_END_SCREEN);
                fullDrawScore(6, 52, nextAppState.garbageCollected, RED);

                state = APP_EXIT_NO_DRAW;
                break;
            case APP_EXIT_NO_DRAW:
                if (KEY_JUST_PRESSED(BUTTON_SELECT, currentButtons, previousButtons)) {
                    state = START;
                } else if (KEY_JUST_PRESSED(BUTTON_START, currentButtons, previousButtons)) {
                    state = APP_INIT;
                }
                break;
            }

        // Store the current state of the buttons
        previousButtons = currentButtons;
        vBlankCounter++;
    }
    return 0;
}
