/*=============================================================================
   Copyright (c) 2014-2023 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include <inf/driver.h>
#include <stddef.h>

#if defined(__has_include)
# if __has_include(<dac.h>)
#  include <dac.h>
#  define CYCFI_INFINITY_HAS_DAC 1
# endif
#endif

#if !defined(CYCFI_INFINITY_HAS_DAC)
# define CYCFI_INFINITY_HAS_DAC 0
#endif

// Main setup and loop
__attribute__((weak))
void setup() {}

__attribute__((weak))
void loop() {}

// Timer interrupts
__attribute__((weak))
void timer2_interrupt() {}

__attribute__((weak))
void timer3_interrupt() {}

// ADC callbacks
__attribute__((weak))
void adc_in_half(uint16_t* samples, size_t size) {}

__attribute__((weak))
void adc_in_full(uint16_t* samples, size_t size) {}

__attribute__((weak))
void adc1_in_half(uint16_t* samples, size_t size) {}

__attribute__((weak))
void adc1_in_full(uint16_t* samples, size_t size) {}

__attribute__((weak))
void adc2_in_half(uint16_t* samples, size_t size) {}

__attribute__((weak))
void adc2_in_full(uint16_t* samples, size_t size) {}

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

// DAC 1 and 2 out
__attribute__((weak))
void dac1_out(uint16_t val)
{
#if CYCFI_INFINITY_HAS_DAC && defined(INFINITY_DAC_HANDLE)
   volatile uint32_t tmp = (uint32_t)INFINITY_DAC_HANDLE.Instance + DAC_DHR12R1_ALIGNMENT(DAC_ALIGN_12B_R);
   *(volatile uint32_t*) tmp = val;
#endif
}

__attribute__((weak))
void dac2_out(uint16_t val)
{
#if CYCFI_INFINITY_HAS_DAC && defined(INFINITY_DAC_HANDLE)
   volatile uint32_t tmp = (uint32_t)INFINITY_DAC_HANDLE.Instance + DAC_DHR12R2_ALIGNMENT(DAC_ALIGN_12B_R);
   *(volatile uint32_t*) tmp = val;
#endif
}

// GPIO Interrupt
__attribute__((weak))
void gpio_interrupt(int pin) {}
