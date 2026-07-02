/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
// C interface barrier for the ADC subsystem: the streaming DMA input hooks
// (half/full transfer callbacks the app overrides) plus a polled, blocking,
// fixed-sequence multi-channel scan (adc_read_all). The application includes
// inf/adc.hpp (the C++ facade + config constants), not this header.
// Implementation is board-specific, in Core/Src/adc.c.
#if !defined(CYCFI_INFINITY_ADC_H_JULY_2_2026)
#define CYCFI_INFINITY_ADC_H_JULY_2_2026

// Derived DMA buffer sizes (samples * channels), when the board's config
// leaves them unspecified.
#if defined(INFINITY_HAS_ADC) && !defined(INFINITY_ADC_BUFFER_SIZE) \
   && defined(INFINITY_NUM_SAMPLES) && defined(INFINITY_NUM_CHANNELS)
#define INFINITY_ADC_BUFFER_SIZE (INFINITY_NUM_SAMPLES * INFINITY_NUM_CHANNELS)
#endif

#if defined(INFINITY_HAS_ADC1) && !defined(INFINITY_ADC1_BUFFER_SIZE) \
   && defined(INFINITY_ADC1_NUM_SAMPLES) && defined(INFINITY_ADC1_NUM_CHANNELS)
#define INFINITY_ADC1_BUFFER_SIZE \
   (INFINITY_ADC1_NUM_SAMPLES * INFINITY_ADC1_NUM_CHANNELS)
#endif

#if defined(INFINITY_HAS_ADC2) && !defined(INFINITY_ADC2_BUFFER_SIZE) \
   && defined(INFINITY_ADC2_NUM_SAMPLES) && defined(INFINITY_ADC2_NUM_CHANNELS)
#define INFINITY_ADC2_BUFFER_SIZE \
   (INFINITY_ADC2_NUM_SAMPLES * INFINITY_ADC2_NUM_CHANNELS)
#endif

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Streaming ADC DMA input hooks: called for the half and full transfer of the
// circular DMA buffer. The app overrides these (weak no-op default in
// driver.c); C linkage is inherited from these declarations.
#if defined(INFINITY_HAS_ADC)
void adc_in_half(volatile uint16_t* samples, size_t size);
void adc_in_full(volatile uint16_t* samples, size_t size);
// Board multi-ADC input hooks (adc.c): one hook per extra ADC, called for both
// the half and full DMA transfer.
void adc2_in(volatile uint16_t* samples, size_t size);
void adc3_in(volatile uint16_t* samples, size_t size);
#endif

#if defined(INFINITY_HAS_ADC1)
void adc1_in_half(volatile uint16_t* samples, size_t size);
void adc1_in_full(volatile uint16_t* samples, size_t size);
#endif

#if defined(INFINITY_HAS_ADC2)
void adc2_in_half(volatile uint16_t* samples, size_t size);
void adc2_in_full(volatile uint16_t* samples, size_t size);
#endif

// Polled, blocking, fixed-sequence scan of every channel: one HAL_ADC_Start,
// then poll-and-read each in turn. Fills out[]; returns the count actually
// converted (the board's full channel count on success, fewer on timeout).
int adc_read_all(uint16_t* out);

#ifdef __cplusplus
}
#endif

#endif
