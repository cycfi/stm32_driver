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

#if defined(DWT_CTRL_CYCCNTENA_Msk)
   void start_cycles()
   {
      CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
# if defined(STM32H7)
      DWT->LAR = 0xC5ACCE55;        // the M7's DWT is locked at reset
# endif
      DWT->CYCCNT = 0;
      DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
   }

   std::uint32_t cycles()
   {
      return DWT->CYCCNT;
   }
#endif
}}
