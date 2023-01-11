/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"

#define BUFFER_LENGTH 16

uint16_t get_block(uint8_t *buffer) {
    uint16_t buffer_index = 0;

    while(true) {
        int c = getchar_timeout_us(100);
        if(c != PICO_ERROR_TIMEOUT && buffer_index < BUFFER_LENGTH) {
            buffer[buffer_index++] = (c & 0xFF);
        } else {
            break;
        }
    }
    return buffer_index;
}

int main() {
#ifndef PICO_DEFAULT_LED_PIN
#warning blink example requires a board with a regular LED
#else
    uint8_t *buffer;
    uint16_t buffer_index = 0;
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    stdio_init_all();
    
    printf("Hello, world!\n");

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_put(LED_PIN, 1);
    while (true) {
        buffer_index = get_block(buffer);
        if(&buffer[0] == 102) {
            break;
        }
    }

    gpio_put(LED_PIN, 0);
#endif
}

