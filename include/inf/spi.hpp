/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_SPI_HPP_JULY_2_2026)
#define CYCFI_INFINITY_SPI_HPP_JULY_2_2026

#include <inf/detail/spi.h>
#include <cstdint>

// C++ facade over SPI port A (the non-blocking transfers). The matching
// *_complete callbacks are hooks the app defines as inf::hooks::spia_*.

namespace cycfi { namespace infinity
{
#if defined(INFINITY_HAS_SPIA)
   struct spi
   {
      static void transmit(std::uint8_t* data, std::uint16_t size)
      {
         spia_transmit(data, size);
      }

      static void receive(std::uint8_t* data, std::uint16_t size)
      {
         spia_receive(data, size);
      }

      static void transmit_receive(
         std::uint8_t* tx_data, std::uint8_t* rx_data, std::uint16_t size)
      {
         spia_transmit_receive(tx_data, rx_data, size);
      }
   };
#endif
}}

// SPI port A's completion hooks (global C ABI). The app defines the ones it
// needs (e.g. `void spia_receive_complete() { ... }`), overriding the weak
// no-op default. A copy of the barrier declaration in inf/detail/spi.h,
// surfaced here so the app sees the hook contract from this facade.
#if defined(INFINITY_HAS_SPIA)
extern "C"
{
   void spia_transmit_complete();
   void spia_receive_complete();
   void spia_transmit_receive_complete();
}
#endif

#endif
