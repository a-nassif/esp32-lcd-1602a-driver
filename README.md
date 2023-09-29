# ESP32 LCD 1602a Driver

ESP32 1602a LCD module driver. This is a very common module with dev kits and small electronic devices. The driver is not perfect but gets you going.

Check the exmaple which prints "Hello World!" to you display.

Please check the data sheet [here](https://cdn-shop.adafruit.com/datasheets/TC1602A-01T.pdf) for referennce on configuration bits.

This was tested on ESP32 Wroom32E module on an ESP32 devkitc.

The driver runs in 4 bit mode for minimal use of GPIO pins.

You will notice milli-second delays added between commands since the ESP much faster than the lcd controller.

## Config

6 pins need to be defined/mapped in your code and connected from board to LCd other than the power pins.

EN: enable pin

RS: Register Select

D4-D7: Data pins

## Running

Please check the example for usage. 

Please make sure you keep the following (as in the example) before starting to write to LCD. These lines set the LCD in write mode, it was left outside the header file in case more configs are needed to be set.

```
// set RS high for write mode
gpio_set_level(RS_PIN, 1);
vTaskDelay(100 / portTICK_PERIOD_MS);
```

## Usage

Clone the repo
```
git clone 
```

Copy and paste the header file `lcd_1602a.h` to your project directory next to your main file or where ever your header files live.

Then import in your main

```
#include "lcd_1602a.h"
```

Define your pins
```
int RS_PIN = 15;
int EN_PIN = 17;
int D4_PIN = 2;
int D5_PIN = 0;
int D6_PIN = 4;
int D7_PIN = 16;
```

Then inside your code, init the lcd with the pins defined, and set to write mode
```
init_lcd(RS_PIN, EN_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

// set RS high for write mode
gpio_set_level(RS_PIN, 1);
vTaskDelay(100 / portTICK_PERIOD_MS);
```

Finally, print to your lcd
```
printToLcd("Hello World!");
```

## Testing

Use at your own risk, this module was intended for test and learning only.



