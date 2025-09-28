#include "buzzer.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"

Buzzer::Buzzer(int pin) {
    this->pin = pin;

    gpio_set_function(this->pin, GPIO_FUNC_PWM);

    int slice_num  = pwm_gpio_to_slice_num(this->pin);
    this->channel = pwm_gpio_to_channel(this->pin);

    this->slice = new Slice(slice_num, 0, true);
}

void Buzzer::play_tone(int freq, double dur) {
    this->slice->set_freq(freq);
    int level = this->slice->get_wrap() / 2; //duty cycle 50%
    
    pwm_set_chan_level(this->slice->get_num(), this->channel, level);
    sleep_ms(dur);

    //this->slice->set_freq(0);
    pwm_set_chan_level(this->slice->get_num(), this->channel, 0);
}

Buzzer::~Buzzer() {
    delete this->slice;
}
