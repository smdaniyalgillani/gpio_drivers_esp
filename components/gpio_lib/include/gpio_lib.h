#include <driver/gpio.h>
#include "esp_err.h"
#include "esp_log.h"
typedef enum {
    PULL_NONE,
    PULL_UP,
    PULL_DOWN
}PinPullMode;

void pinMode(uint64_t gpio_pin, gpio_mode_t gpio_mode, PinPullMode pull);


void pinWrite(gpio_num_t gpio_num, uint32_t level);
int pinRead(gpio_num_t gpio_num, bool LOG_EN);