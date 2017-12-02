/* mbed Example Program
 * Copyright (c) 2006-2014 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/******************************************************************* Includes */
#include "mbed.h"
#include "ADJDs311.h"

/******************************************************************** Globals */
ADJDs311 colorSensor(P5_0, P5_2, P1_14);    // SDA, SCL, LED
Serial pc(P0_5, P0_4);                      // tx, rx

/****************************************************************** Functions */

/**
 * Main Function
 */
int main() {

    RGBC color, cap, inte, offset;

    /* Turn on the board LED */
    colorSensor.ledMode(true);

    /* Calibrate sensor */
    pc.printf("Calibartion started.\n\rPress any key to continue...\n\r");
    while(!pc.readable());
    colorSensor.calibrate();

    /* Discard any received chars */
    while(pc.readable())
    {
        pc.getc();
    }

    /* Get and set sensor offset */
    pc.printf("Getting offset\n\rPress any key to continue...\n\r");
    while(!pc.readable());
    offset = colorSensor.setOffset();

    /* Discard any received chars */
    while(pc.readable())
    {
        pc.getc();
    }

    /* Get the gain of the capacitors and the integration time slot */
    cap = colorSensor.getColorCap();
    inte = colorSensor.getColorInt();

    /* Print calibration data */
    pc.printf("\n\n\n\rCalibartion completed.\n\r");
    pc.printf("\nCaps:\t\tr: %4d,\tg: %4d,\tb: %4d,\tc: %4d\n\r", cap.red, cap.green, cap.blue, cap.clear);
    pc.printf("Ints:\t\tr: %4d,\tg: %4d,\tb: %4d,\tc: %4d\n\r", inte.red, inte.green, inte.blue, inte.clear);
    pc.printf("Offsets:\tr: %4d,\tg: %4d,\tb: %4d,\tc: %4d\n\r", offset.red, offset.green, offset.blue, offset.clear);

    /* Press key to continue with color measurement */
    pc.printf("\nPress any key to continue\n\r");
    while(!pc.readable());
    while(pc.readable())
    {
        pc.getc();
    }

    /* Turn on the Led and print continuously the color data */
    colorSensor.ledMode(true);
    while(1) {
        /* Get color data from the senosr */
        color = colorSensor.read();
        pc.printf("red: %4d,\tgreen: %4d,\tblue: %4d,\tclear: %4d\r", color.red, color.green, color.blue, color.clear);
        wait(0.15);
    }
}

/*EOF*/
