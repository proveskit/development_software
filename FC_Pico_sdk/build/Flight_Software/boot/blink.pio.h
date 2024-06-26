// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// ----- //
// blink //
// ----- //

#define blink_wrap_target 0
#define blink_wrap 19

static const uint16_t blink_program_instructions[] = {
            //     .wrap_target
    0xf301, //  0: set    pins, 1                [19]
    0xb342, //  1: nop                           [19]
    0xb342, //  2: nop                           [19]
    0xb342, //  3: nop                           [19]
    0xb342, //  4: nop                           [19]
    0xb342, //  5: nop                           [19]
    0xb342, //  6: nop                           [19]
    0xb342, //  7: nop                           [19]
    0xb342, //  8: nop                           [19]
    0xb342, //  9: nop                           [19]
    0xf300, // 10: set    pins, 0                [19]
    0xb342, // 11: nop                           [19]
    0xb342, // 12: nop                           [19]
    0xb342, // 13: nop                           [19]
    0xb342, // 14: nop                           [19]
    0xb342, // 15: nop                           [19]
    0xb342, // 16: nop                           [19]
    0xb342, // 17: nop                           [19]
    0xb342, // 18: nop                           [19]
    0xb342, // 19: nop                           [19]
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program blink_program = {
    .instructions = blink_program_instructions,
    .length = 20,
    .origin = -1,
};

static inline pio_sm_config blink_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + blink_wrap_target, offset + blink_wrap);
    return c;
}

    //Helper Function for use in C program to initialize this PIO program
    void blink_program_init(PIO pio, uint sm, uint offset, uint pin, float div){
        // Sets up state machine and wrap target. This function is auto generated in blink.pio.h
        pio_sm_config cfg=blink_program_get_default_config(offset);
        //allow PIO to control GPIO pin as output
        pio_gpio_init(pio,pin);
        // Set the pin direction to output (in PIO)
        pio_sm_set_consecutive_pindirs(pio, sm, pin, 1, true);
        //connect pin to SET pin (control with 'set' instruction)
        sm_config_set_set_pins(&cfg, pin, 1);
        // Set the clock divider for the state machine
        sm_config_set_clkdiv(&cfg, div);
        // Load configuration and jump to start of the program
        pio_sm_init(pio, sm, offset, &cfg);
    }

#endif

