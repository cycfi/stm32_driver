/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
// C interface barrier for buffered serial transmit (UART): bytes queue in a
// ring that the UART's interrupt drains, so a write never waits on the line.
// The application includes inf/uart.hpp (the C++ facade), not this header.
// Implementation in the board's Core (infinity: Core/Src/usart.c). Gated by
// INFINITY_HAS_UART.
#if !defined(CYCFI_INFINITY_UART_H_SEPTEMBER_26_2026)
#define CYCFI_INFINITY_UART_H_SEPTEMBER_26_2026

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Queue `size` bytes on `port` (0 = the board's first UART), all or none.
// Returns 1 if queued, 0 if the ring has no room for all of them.
int      uart_write(unsigned port, const uint8_t* data, uint32_t size);

// Bytes that can be queued on `port` now.
uint32_t uart_space(unsigned port);

#ifdef __cplusplus
}
#endif

#endif
