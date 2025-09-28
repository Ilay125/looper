#ifndef __CONSTS__
#define __CONSTS__

#define BUZZER_PIN 19

#define OCTAVE_SIZE 8

#define C6_PIN 15
#define D6_PIN 14
#define E6_PIN 13
#define F6_PIN 12
#define G6_PIN 11
#define A6_PIN 10
#define B6_PIN 9
#define C7_PIN 8

#define KEY_TIME 1 // ms
#define MAX_INTENSITY_SOUND 5000;
#define SOUND_DECAY_FACTOR 1.01;

#define REC_BTN_PIN 2
#define REC_LED_PIN 3

#define PLAY_BTN_PIN 4
#define PLAY_LED_PIN 5



// C6-C7 frequency [Hz]
const int TONES[] = {1047,
                    1175,
                    1319,
                    1397,
                    1568,
                    1760,
                    1976,
                    2093};



#endif