/*=============================================================================
   Copyright (c) 2014-2022 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include <inf/driver.h>
#include <stddef.h>

// Main setup and loop
__attribute__((weak))
void setup() {}

__attribute__((weak))
void loop() {}

// Timer interrupt
__attribute__((weak))
void timer3_interrupt() {}

// ADC callbacks
__attribute__((weak))
void adc_in_half(uint16_t* samples, size_t size) {}

__attribute__((weak))
void adc_in_full(uint16_t* samples, size_t size) {}

// SPI functions
__attribute__((weak))
void spia_transmit(uint8_t* data, uint16_t size) {}

__attribute__((weak))
void spia_transmit_complete() {}

__attribute__((weak))
void spia_receive(uint8_t* data, uint16_t size) {}

__attribute__((weak))
void spia_receive_complete() {}

__attribute__((weak))
void spia_transmit_receive(uint8_t* tx_data, uint8_t* rx_data, uint16_t size) {}

__attribute__((weak))
void spia_transmit_receive_complete() {}

// USB CDC transmit
uint8_t CDC_Transmit_FS(uint8_t* buff, uint16_t len);

uint8_t CDC_transmit(uint8_t* buff, uint16_t len)
{
   return CDC_Transmit_FS(buff, len);
}

// GPIO Interrupt
__attribute__((weak))
void gpio_interrupt(int pin) {}
