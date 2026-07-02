/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_TIMER_HPP_JULY_2_2026)
#define CYCFI_INFINITY_TIMER_HPP_JULY_2_2026

// The periodic-timer interrupt hooks (global C ABI). The app defines the ones
// it needs (e.g. `void timer3_interrupt() { ... }`), overriding the weak
// no-op default. A copy of the barrier declaration in inf/detail/timer.h,
// surfaced here so the app never reaches into detail/.

extern "C"
{
#if defined(INFINITY_HAS_TIMER2)
   void timer2_interrupt();
#endif

#if defined(INFINITY_HAS_TIMER3)
   void timer3_interrupt();
#endif
}

#endif
