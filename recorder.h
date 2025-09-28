#ifndef __RECORDER__
#define __RECORDER__

#include <vector>
#include "pico/stdlib.h"
#include "wrap/buzzer.h"
#include "wrap/button.h"


class Recorder {
    bool is_rec;
    bool is_play;
    uint64_t time_last_event;
    std::vector<absolute_time_t> time_rec;
    std::vector<int> key_rec;

    public:
        Recorder();
        void add_key(int key, absolute_time_t now);
        int play(Buzzer& buzz, Button& play);
        void clear();

        void set_rec(bool state);
        void toggle_rec();
        bool get_rec_state();

        void set_play(bool state);
        void toggle_play();
        bool get_play_state();
};

#endif