/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_SYSTEM_HPP_JULY_1_2026)
#define CYCFI_INFINITY_SYSTEM_HPP_JULY_1_2026

// System-control facade. Declaration only -- no HAL/CMSIS here. The impl lives
// in source/inf/system.cpp behind inf/detail/hal.hpp, so an application can call
// inf::system_reset() without seeing the platform.

namespace cycfi { namespace infinity
{
   // Request an MCU system reset (ARM Cortex AIRCR). Does not return.
   void system_reset();
}}

#endif
