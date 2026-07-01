/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_DETAIL_HAL_HPP_JULY_1_2026)
#define CYCFI_INFINITY_DETAIL_HAL_HPP_JULY_1_2026

// The vendor HAL/LL/CMSIS headers, selected per MCU family. This is the ONE
// place the driver reaches into the platform SDK. It is a detail header: only
// driver implementation (.c / .cpp) and the inf/*.hpp facades include it, never
// the application. Keeping it out of the app-facing headers (support.hpp, the
// facades' public surface) is what lets an application stay free of HAL.

// The vendor headers below use fixed-width ints / size_t but do not include the
// standard headers themselves; pull them in first so this header is self-
// contained regardless of include order.
#include <stdint.h>
#include <stddef.h>

#if defined(STM32H7)
# include <system_stm32h7xx.h>
# include <stm32h7xx_ll_utils.h>
# include <stm32h7xx_hal.h>
#elif defined(STM32F4)
# include <system_stm32f4xx.h>
# include <stm32f4xx_ll_utils.h>
# include <stm32f4xx_hal.h>
#elif defined(STM32C0)
# include <system_stm32c0xx.h>
# include <stm32c0xx_ll_utils.h>
# include <stm32c0xx_hal.h>
#endif

#endif
