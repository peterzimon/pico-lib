#include "button.h"

uint32_t Button::get_now_() {
    return to_ms_since_boot(get_absolute_time());
}

/* ------------------------ ⬆︎ PRIVATE | PUBLIC ⬇︎  -------------------------- */

Button::Button (uint8_t pin, uint32_t debounce_time) {
    pin_ = pin;
    debounce_time_ = debounce_time;
}

void Button::init_gpio() {
    gpio_init(pin_);
    gpio_set_dir(pin_, GPIO_IN);
    gpio_pull_up(pin_);
}

bool Button::is_pressed() {
    bool btn_read = !gpio_get(pin_);

    if (btn_read) {
        pressed_ = true;
        previous_debounce_ms_ = get_now_();
    } else {
        if (get_now_() - previous_debounce_ms_ > debounce_time_) {
            pressed_ = false;
        }
    }

    return pressed_;
}

bool Button::is_released() {
    released_ = false;
    bool btn_read = !gpio_get(pin_);

    if (btn_read) {
        previous_debounce_ms_ = get_now_();
        pressed_ = true;
    } else {
        if ((get_now_() - previous_debounce_ms_ > debounce_time_) && pressed_) {
            released_ = true;
            pressed_ = false;
        }
    }

    return released_;
}