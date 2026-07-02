/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
// C interface barrier for a polled, blocking, fixed-sequence multi-channel
// ADC scan. The application includes inf/adc.hpp (the C++ facade), not this
// header. Implementation is board-specific, in Core/Src/adc.c.
#if !defined(CYCFI_INFINITY_ADC_H_JULY_2_2026)
#define CYCFI_INFINITY_ADC_H_JULY_2_2026

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Scan every channel in the board's fixed ADC sequence: one HAL_ADC_Start,
// then poll-and-read each channel in turn. Fills out[]; returns the count
// actually converted (the board's full channel count on success, fewer if a
// conversion timed out).
int adc_read_all(uint16_t* out);

#ifdef __cplusplus
}
#endif

#endif
