#include "gpio_lib.h"

void pinMode(uint64_t gpio_pin, gpio_mode_t gpio_mode, PinPullMode pull)
{
    gpio_config_t new_gpio = {
        .pin_bit_mask = (1ULL << gpio_pin),
        .mode = gpio_mode,
        .pull_up_en = (pull == PULL_UP) ? GPIO_PULLUP_ENABLE : GPIO_PULLUP_DISABLE,
        .pull_down_en = (pull == PULL_DOWN) ? GPIO_PULLDOWN_ENABLE : GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };

    gpio_config(&new_gpio);
}