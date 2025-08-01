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

void pinWrite(gpio_num_t gpio_num, uint32_t level)
{
    gpio_set_level(gpio_num, level);
}

int pinRead(gpio_num_t gpio_num, bool LOG_EN)
{
    int level = gpio_get_level(gpio_num);

    if (LOG_EN) {
        ESP_LOGI("GPIO", "Value at Pin %d is %d", gpio_num, level);
    }

    return level;
}