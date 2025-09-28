#include "led.h"
#include "pico/stdlib.h"

LED::LED(int pin) {
    this->pin = pin;
    this->state = false;

    gpio_init(this->pin);
    gpio_set_dir(this->pin, GPIO_OUT);

    gpio_put(this->pin, this->state);
}

void LED::set(bool state) {
    this->state = state;
    gpio_put(this->pin, this->state);
}

bool LED::get() {
    return this->state;
}

void LED::toggle() {
    this->state = !this->state;
    gpio_put(this->pin, this->state);
}

void LED::blink(int times, int delay_ms) {
    for (int i = 0; i < times; i++) {
        this->toggle();
        sleep_ms(delay_ms);
    }
}