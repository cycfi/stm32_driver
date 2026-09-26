/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_FLASH_HPP_SEPTEMBER_26_2026)
#define CYCFI_INFINITY_FLASH_HPP_SEPTEMBER_26_2026

#include <cstddef>
#include <cstdint>

// Persistent storage in the MCU's own flash, a page at a time: erase a
// page, then program it. A page is the G0/C0's 2 KB page, or the F4's
// sector (16, 64 or 128 KB). Code runs from the same flash, so the CPU
// stalls while it erases (a G0 page: about 20 to 40 ms; an F4 128 KB
// sector: 1 to 2 s) and programs: use it only where a stall that long is
// harmless, and write rarely (about 10,000 erases). STM32G0, C0 and F4.

namespace cycfi { namespace infinity
{
   struct flash
   {
      // The size of the page that holds `address`.
      static std::uint32_t page_size(std::uintptr_t address);

      // Erase the page that holds `address`. True on success.
      static bool erase_page(std::uintptr_t address);

      // Program `size` bytes into erased flash at `address`. Both must be
      // multiples of 8 (the G0 programs 64-bit double words; the F4 words).
      // True on success.
      static bool program(std::uintptr_t address, void const* data,
                          std::size_t size);
   };
}}

#endif
