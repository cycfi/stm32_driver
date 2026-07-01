/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include <inf/system.hpp>
#include <inf/detail/hal.hpp>

namespace cycfi { namespace infinity
{
   void system_reset()
   {
      NVIC_SystemReset();
   }
}}
