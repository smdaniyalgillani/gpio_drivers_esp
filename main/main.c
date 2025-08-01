#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "gpio_lib.h"

void app_main(void)
{
    pinMode(17,GPIO_MODE_INPUT, PULL_DOWN);
    pinMode(10, GPIO_MODE_OUTPUT, PULL_NONE);
    while (1)
    {
        pinWrite(10, 1);
        pinRead(17, true);
        vTaskDelay(pdMS_TO_TICKS(500));
        pinWrite(10, 0);
        pinRead(17, true);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    
   
}
