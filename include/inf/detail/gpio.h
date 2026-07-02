/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
// C interface barrier for the EXTI GPIO interrupt hook. The board's EXTI ISR
// calls gpio_interrupt(pin); the app overrides it (weak no-op default in
// driver.c). C linkage is inherited from this declaration.
#if !defined(CYCFI_INFINITY_GPIO_H_JULY_2_2026)
#define CYCFI_INFINITY_GPIO_H_JULY_2_2026

#ifdef __cplusplus
extern "C" {
#endif

#if defined(INFINITY_HAS_GPIO_INTERRUPT)
void gpio_interrupt(int pin);
#endif

#ifdef __cplusplus
}
#endif

#endif
