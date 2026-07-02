/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
// C interface barrier for SPI port A: non-blocking transfers, each paired
// with a completion hook the app overrides (weak no-op default in driver.c).
// The application includes inf/spi.hpp (the C++ facade) for the calls, and
// defines the *_complete hooks directly (C linkage inherited from here).
#if !defined(CYCFI_INFINITY_SPI_H_JULY_2_2026)
#define CYCFI_INFINITY_SPI_H_JULY_2_2026

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(INFINITY_HAS_SPIA)
// Non-blocking transmit
void spia_transmit(uint8_t* data, uint16_t size);
void spia_transmit_complete();           // completion hook (app overrides)

// Non-blocking receive
void spia_receive(uint8_t* data, uint16_t size);
void spia_receive_complete();            // completion hook (app overrides)

// Non-blocking transmit + receive
void spia_transmit_receive(uint8_t* tx_data, uint8_t* rx_data, uint16_t size);
void spia_transmit_receive_complete();   // completion hook (app overrides)
#endif

#ifdef __cplusplus
}
#endif

#endif
