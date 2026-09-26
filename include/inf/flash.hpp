/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_FLASH_HPP_SEPTEMBER_26_2026)
#define CYCFI_INFINITY_FLASH_HPP_SEPTEMBER_26_2026

#include <cstddef>
#include <cstdint>

// Persistent storage in the MCU's own flash, a page at a time: erase a
// page, then program it. Code runs from the same flash, so the CPU stalls
// while it erases (a G0 page: about 20 to 40 ms) and programs: use it only
// where a stall that long is harmless, and write rarely (a G0 page lasts
// about 10,000 erases). STM32G0 and C0 only for now.

namespace cycfi { namespace infinity
{
   struct flash
   {
      static std::uint32_t page_size();

      // Erase the page that holds `address`. True on success.
      static bool erase_page(std::uintptr_t address);

      // Program `size` bytes into erased flash at `address`. Both must be
      // multiples of 8 (the G0 programs 64-bit double words). True on
      // success.
      static bool program(std::uintptr_t address, void const* data,
                          std::size_t size);
   };
}}

#endif
