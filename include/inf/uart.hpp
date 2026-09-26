/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_UART_HPP_SEPTEMBER_26_2026)
#define CYCFI_INFINITY_UART_HPP_SEPTEMBER_26_2026

#include <inf/detail/uart.h>
#include <cstdint>

// C++ facade over buffered serial transmit. port is a small index (0 = the
// board's first UART). A write queues all its bytes or none, so a message
// is never split; the UART interrupt sends them in the background.

namespace cycfi { namespace infinity
{
   struct uart
   {
      static bool write(unsigned port, std::uint8_t const* data,
                        std::uint32_t size)
      {
         return uart_write(port, data, size) != 0;
      }

      static std::uint32_t space(unsigned port)
      {
         return uart_space(port);
      }
   };
}}

#endif
