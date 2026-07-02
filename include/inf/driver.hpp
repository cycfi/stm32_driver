/*=============================================================================
   Copyright (c) 2014-2023 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
// Umbrella C++ header: the C barrier plus the board configuration constants
// (sys_clock, sps, num_channels, ...). Kept for the many app/test units that
// include it for those constants; new code can include the focused facades
// (inf/adc.hpp, inf/clock.hpp, ...) directly instead.
#if !defined(CYCFI_INFINITY_DRIVER_HPP_JULY_25_2022)
#define CYCFI_INFINITY_DRIVER_HPP_JULY_25_2022

#include <inf/detail/driver.h>
#include <inf/clock.hpp>   // sys_clock (+ millis / delay_ms)
#include <inf/adc.hpp>     // sps, num_samples, num_channels, adc_* (+ inf::adc)
#include <inf/dac.hpp>     // dac_resolution (+ inf::dac)

#endif
