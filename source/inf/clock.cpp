/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include <inf/clock.hpp>
#include <inf/detail/hal.hpp>

namespace cycfi { namespace infinity
{
   std::uint32_t const clock_speed = SystemCoreClock;

   std::uint32_t millis()
   {
      return HAL_GetTick();
   }

   void delay_ms(std::uint32_t ms)
   {
      LL_mDelay(ms);
   }
}}
