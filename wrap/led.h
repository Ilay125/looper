#ifndef __LED__
#define __LED__

class LED {
    int pin;
    bool state;

    public:
        /**
         * @fn LED
         * @brief Construct a new LED object.
         */
        LED(int pin);

        /**
         * @fn set
         * @brief Set the LED state.
         * @param state true to turn on, false to turn off.
         */
        void set(bool state);

        /**
         * @fn get
         * @brief Get the current state of the LED.
         * @return true if on, false if off.
         */
        bool get();

        /**
         * @fn toggle
         * @brief Toggle the state of the LED.
         */
        void toggle();

        /**
         * @fn blink
         * @brief Blink the LED a specified number of times with a given delay.
         * @param times Number of times to blink.
         * @param delay_ms Delay in milliseconds between on and off states.
         */
        void blink(int times, int delay_ms);
};

#endif