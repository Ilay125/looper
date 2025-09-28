#include <stdio.h>
#include "pico/stdlib.h"
#include <vector>
#include "pico/multicore.h"

#include "constants.h"
#include "wrap/buzzer.h"
#include "wrap/debug.h"
#include "wrap/button.h"
#include "wrap/led.h"
#include "recorder.h"

int key_amp[OCTAVE_SIZE] = { 0 };

void speaker() {
    
    Buzzer buzzer(BUZZER_PIN);

    for (int t : TONES) {
        buzzer.play_tone(t, 200);
    }

    int sum_weight_freq = 0;
    int sum_amps = 0;

    while(1) {
        for (int i = 0; i < OCTAVE_SIZE; i++) {
            if (key_amp[i] > 0) {
                sum_weight_freq += key_amp[i] * TONES[i];
                sum_amps += key_amp[i];
                key_amp[i] /= SOUND_DECAY_FACTOR;
                printf("key amp=%d", key_amp[i]);
            }
        }

        buzzer.play_tone(sum_weight_freq / sum_amps, KEY_TIME);
        sum_weight_freq = 0;
        sum_amps = 0;
    }
}
                   
int main()
{
    stdio_init_all();

    multicore_launch_core1(speaker);

    
    Debug debug;

    Button keys_btns[] = {Button(C6_PIN),
                    Button(D6_PIN),
                    Button(E6_PIN),
                    Button(F6_PIN),
                    Button(G6_PIN),
                    Button(A6_PIN),
                    Button(B6_PIN),
                    Button(C7_PIN)};
    
    
    Button rec_btn(REC_BTN_PIN);
    LED rec_led(REC_LED_PIN);
    
    Button play_btn(PLAY_BTN_PIN);
    LED play_led(PLAY_LED_PIN);


    Recorder rec;

    // Listener
    while (1) {
        if (!rec.get_play_state()) {

            for (int i = 0; i < OCTAVE_SIZE; i++) {
                if (keys_btns[i].is_pressed()) {
                    printf("pressed %d; ", i);

                    if (rec.get_rec_state()) {
                        rec.add_key(i, get_absolute_time());
                    }
                
                    key_amp[i] = MAX_INTENSITY_SOUND;
                }
            }

            if (rec_btn.is_pressed()) {
                rec.toggle_rec();
                rec_led.set(rec.get_rec_state());

                if (rec.get_rec_state()) {
                    rec.clear();
                    printf("Recording started\n");
                } else {
                    printf("Recording ended\n");
                }
            }

        }
        
        if (play_btn.is_pressed() && !rec.get_rec_state()) {
            rec.set_play(true);
            play_led.set(true);
            
            rec.play(key_amp, play_btn);

            rec.set_play(false);
            play_led.set(false);
        }
    }

}
