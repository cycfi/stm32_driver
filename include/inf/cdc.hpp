/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_CDC_HPP_JULY_1_2026)
#define CYCFI_INFINITY_CDC_HPP_JULY_1_2026

#include <inf/detail/cdc.h>
#include <cstdint>

// C++ facade over the USB CDC host link. Outbound goes through
// inf::cdc::transmit; inbound host bytes arrive via the eth_cdc_rx hook,
// which the application defines as inf::hooks::eth_cdc_rx.

namespace cycfi { namespace infinity
{
   struct cdc
   {
      // Queue `len` bytes to the host. Returns 0 on success, non-zero if the
      // endpoint is still busy with the previous buffer.
      static std::uint8_t transmit(std::uint8_t* data, std::uint16_t len)
      {
         return CDC_Transmit_HS(data, len);
      }
   };
}}

// The inbound host-bytes hook (global C ABI). The app defines it (e.g.
// `void eth_cdc_rx(...) { ... }`), overriding the weak no-op default. A copy
// of the barrier declaration in inf/detail/cdc.h, surfaced here so the app
// sees the hook contract from this facade.
extern "C"
{
   void eth_cdc_rx(std::uint8_t const* buf, std::uint32_t len);
}

#endif
