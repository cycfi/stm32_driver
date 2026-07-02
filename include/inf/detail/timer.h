/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
// C interface barrier for the periodic-timer interrupt hooks. The board's
// timer ISR calls timerN_interrupt(); the app overrides it (weak no-op
// default in driver.c). C linkage is inherited from these declarations.
#if !defined(CYCFI_INFINITY_TIMER_H_JULY_2_2026)
#define CYCFI_INFINITY_TIMER_H_JULY_2_2026

#ifdef __cplusplus
extern "C" {
#endif

#if defined(INFINITY_HAS_TIMER2)
void timer2_interrupt();
#endif

#if defined(INFINITY_HAS_TIMER3)
void timer3_interrupt();
#endif

#ifdef __cplusplus
}
#endif

#endif
