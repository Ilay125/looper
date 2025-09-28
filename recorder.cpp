#include "recorder.h"
#include "constants.h"
#include <stdio.h>
#include "constants.h"

Recorder::Recorder() {
    this->is_rec = false;
    this->is_play = false;
    this->time_last_event = get_absolute_time();
    this->time_rec.clear();
    this->key_rec.clear();
}

void Recorder::add_key(int key, absolute_time_t now) {
    uint64_t diff = absolute_time_diff_us(this->time_last_event, now);
    //diff -= KEY_TIME * 1000; // time in us
    printf("diff=%llu\n", diff);

    this->time_rec.push_back(diff);
    this->key_rec.push_back(key);
    this->time_last_event = now;
}


void Recorder::play(int key_amps[], Button& play) {
    while(!play.is_pressed()) {
        for (int i = 0; i < key_rec.size(); i++) {
            if (play.is_pressed()) {
                return;
            }

            uint64_t delay = this->time_rec.at(i);
            sleep_us(delay);
            
            int key = this->key_rec.at(i);
            key_amps[key] = MAX_INTENSITY_SOUND;
        }
    }
    }
    

void Recorder::clear() {
    this->time_last_event = get_absolute_time();
    this->time_rec.clear();
    this->key_rec.clear();
}

void Recorder::set_rec(bool state) {
    this->is_rec = state;
}

void Recorder::toggle_rec() {
    this->set_rec(!this->is_rec);
}

bool Recorder::get_rec_state() {
    return this->is_rec;
}

void Recorder::set_play(bool state) {
    this->is_play = state;
}

void Recorder::toggle_play() {
    this->set_play(!this->is_play);
}

bool Recorder::get_play_state() {
    return this->is_play;
}