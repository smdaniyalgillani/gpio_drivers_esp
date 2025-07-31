#include <driver/gpio.h>

typedef enum {
    PULL_NONE,
    PULL_UP,
    PULL_DOWN
}PinPullMode;

void pinMode(uint64_t gpio_pin, gpio_mode_t gpio_mode, PinPullMode pull);


void pinRead();
void pinWrite();