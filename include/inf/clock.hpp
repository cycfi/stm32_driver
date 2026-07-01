/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_CLOCK_HPP_JULY_1_2026)
#define CYCFI_INFINITY_CLOCK_HPP_JULY_1_2026

#include <cstdint>

// System time facade. Declarations only -- no HAL here, so an application can
// include this (directly or via support.hpp) and stay platform-clean. The
// implementations live in source/inf/clock.cpp behind inf/detail/hal.hpp.

namespace cycfi { namespace infinity
{
   // Milliseconds since boot (the HAL SysTick counter).
   std::uint32_t millis();

   // Busy-wait delay, in milliseconds.
   void delay_ms(std::uint32_t ms);

   // The MCU core clock (Hz), sampled at startup.
   extern std::uint32_t const clock_speed;
}}

#endif
