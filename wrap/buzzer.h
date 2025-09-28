#ifndef __BUZZER__
#define __BUZZER__

#include "slice.h"

class Buzzer {
    int pin;
    Slice* slice;
    int channel;

    public:
        Buzzer(int pin);
        void play_tone(int freq, double dur);

        ~Buzzer();
};

#endif