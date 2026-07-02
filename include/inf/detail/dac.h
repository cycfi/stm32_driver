/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
// C interface barrier for the DAC outputs. The app pushes samples via
// dacN_out(); the driver writes them to the DAC data register. The
// application includes inf/dac.hpp (the C++ facade), not this header.
#if !defined(CYCFI_INFINITY_DAC_H_JULY_2_2026)
#define CYCFI_INFINITY_DAC_H_JULY_2_2026

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(INFINITY_HAS_DAC)
void dac1_out(uint16_t sample);
void dac2_out(uint16_t sample);
#endif

#ifdef __cplusplus
}
#endif

#endif
