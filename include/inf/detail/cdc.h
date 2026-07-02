/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
// C interface barrier for the USB CDC (virtual COM) host link. The application
// includes inf/cdc.hpp (the C++ facade), not this header. The implementation is
// the CubeMX USB device middleware (usbd_cdc_if.c).
#if !defined(CYCFI_INFINITY_CDC_H_JULY_1_2026)
#define CYCFI_INFINITY_CDC_H_JULY_1_2026

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Queue `len` bytes for transmit to the USB CDC host. Returns 0 (USBD_OK) on
// success, non-zero if the IN endpoint is still busy with the previous buffer.
uint8_t CDC_Transmit_HS(uint8_t* buf, uint16_t len);

// Full-speed transmit wrapper (driver.c -> CDC_Transmit_FS); the HS entry
// above is what inf::cdc uses. Present only on a board with USB CDC.
#if defined(INFINITY_HAS_USB_CDC)
uint8_t CDC_transmit(uint8_t* buff, uint16_t len);
#endif

// Inbound hook: the USB ISR calls this with host-to-device bytes. Weak no-op
// default in the middleware; the application overrides it (strong). Its C
// linkage is inherited from this declaration, so no `extern "C"` is written in
// app code.
void eth_cdc_rx(const uint8_t* buf, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif
