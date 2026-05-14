/*=============================================================================
   Copyright (c) 2014-2023 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_PORT_IMPL_HPP_DECEMBER_20_2015)
#define CYCFI_INFINITY_PORT_IMPL_HPP_DECEMBER_20_2015

#include <cstddef>
#include <cstdint>

#if defined(STM32H7)
# include <stm32h7xx.h>
# include <stm32h7xx_ll_gpio.h>
# include <stm32h7xx_ll_bus.h>
# include <stm32h7xx_ll_system.h>
# include <stm32h7xx_ll_exti.h>
#elif defined(STM32F4)
# include <stm32f4xx.h>
# include <stm32f4xx_ll_gpio.h>
# include <stm32f4xx_ll_bus.h>
# include <stm32f4xx_ll_system.h>
# include <stm32f4xx_ll_exti.h>
#elif defined(STM32C0)
# include <stm32c0xx.h>
# include <stm32c0xx_ll_gpio.h>
# include <stm32c0xx_ll_bus.h>
# include <stm32c0xx_ll_system.h>
# include <stm32c0xx_ll_exti.h>
#endif

namespace cycfi { namespace infinity { namespace detail
{
   ////////////////////////////////////////////////////////////////////////////
   // The ports: We provide template functions for getting the memory mapped
   // ports given a constant N. That way, we can use generic programming.
   //
   // This implementation is for the STM32F4 series.
   ////////////////////////////////////////////////////////////////////////////

   template <std::size_t port>
   GPIO_TypeDef& get_port();

#define INFINITY_IOPORT(N, PORT_NAME)                                          \
   template <>                                                                 \
   inline GPIO_TypeDef& get_port<N>()                                          \
   {                                                                           \
      return *GPIO##PORT_NAME;                                                 \
   }                                                                           \
   /***/

#ifdef GPIOA
  INFINITY_IOPORT(0, A)
#endif
#ifdef GPIOB
  INFINITY_IOPORT(1, B)
#endif
#ifdef GPIOC
  INFINITY_IOPORT(2, C)
#endif
#ifdef GPIOD
  INFINITY_IOPORT(3, D)
#endif
#ifdef GPIOE
  INFINITY_IOPORT(4, E)
#endif
#ifdef GPIOF
  INFINITY_IOPORT(5, F)
#endif
#ifdef GPIOG
  INFINITY_IOPORT(6, G)
#endif
#ifdef GPIOH
  INFINITY_IOPORT(7, H)
#endif
#ifdef GPIOI
  INFINITY_IOPORT(8, I)
#endif

}}}

#endif
