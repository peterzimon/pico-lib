/**
 * Simple button class with debouncing. It can be used to check if the button
 * was pressed or released.
*/

#ifndef _PICO_LIB_BUTTON_H
#define _PICO_LIB_BUTTON_H

#include <pico/stdlib.h>
#include <hardware/gpio.h>

#define DEFAULT_DEBOUNCE_MS 50

class Button
{
private:
    uint8_t pin_;
    uint32_t previous_debounce_ms_;
    uint32_t debounce_time_;
    bool pressed_ = false;
    bool released_ = false;

    uint32_t get_now_();

public:
    Button() { };
    Button (uint8_t pin, uint32_t debounce_time = DEFAULT_DEBOUNCE_MS);

    void init_gpio();
    bool is_pressed();
    bool is_released();
};

#endif