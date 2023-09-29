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

## Testing

Use at your own risk, this module was intended for test and learning only.



