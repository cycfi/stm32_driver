/*=============================================================================
   Copyright (c) 2014-2022 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_DRIVER_HPP_JULY_25_2022)
#define CYCFI_INFINITY_DRIVER_HPP_JULY_25_2022

#include <inf/driver.h>

// Constants
constexpr auto sys_clock = INFINITY_SYS_CLOCK;
constexpr auto sps = INFINITY_SPS;
constexpr auto num_samples = INFINITY_NUM_SAMPLES;
constexpr auto num_channels = INFINITY_NUM_CHANNELS;
constexpr auto adc_buffer_size = num_samples * num_channels;
constexpr auto adc_resolution = INFINITY_ADC_RESOLUTION;
constexpr auto dac_resolution = INFINITY_DAC_RESOLUTION;

#endif
