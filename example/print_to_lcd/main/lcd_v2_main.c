#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "lcd_1602a.h"

int RS_PIN = 15;
int EN_PIN = 17;
int D4_PIN = 2;
int D5_PIN = 0;
int D6_PIN = 4;
int D7_PIN = 16;


static const char *LOGTAG = "example";


void app_main(void)
{
    init_lcd(RS_PIN, EN_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN);

    // Set RS high for write mode
    // This is kept here in case more configs
    //    need to be sent to lcd before print
    gpio_set_level(RS_PIN, 1);
    vTaskDelay(100 / portTICK_PERIOD_MS);

    ESP_LOGI(LOGTAG, "Writing Hello World!");

    // Write to lcd
    printToLcd("Hello World!");

}

