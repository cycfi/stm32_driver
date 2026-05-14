/*=============================================================================
   Copyright (c) 2014-2023 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_DRIVER_HPP_JULY_25_2022)
#define CYCFI_INFINITY_DRIVER_HPP_JULY_25_2022

#include <inf/driver.h>

// Constants
constexpr auto sys_clock = INFINITY_SYS_CLOCK;

#if defined(INFINITY_SPS)
constexpr auto sps = INFINITY_SPS;
constexpr auto num_samples = INFINITY_NUM_SAMPLES;
constexpr auto num_channels = INFINITY_NUM_CHANNELS;
constexpr auto adc_buffer_size = num_samples * num_channels;
constexpr auto adc_resolution = INFINITY_ADC_RESOLUTION;
#endif

#if defined(INFINITY_ADC1_SPS)
constexpr auto adc1_sps = INFINITY_ADC1_SPS;
constexpr auto adc1_num_samples = INFINITY_ADC1_NUM_SAMPLES;
constexpr auto adc1_num_channels = INFINITY_ADC1_NUM_CHANNELS;
constexpr auto adc1_buffer_size = adc1_num_samples * adc1_num_channels;
constexpr auto adc1_resolution = INFINITY_ADC1_RESOLUTION;
#endif

#if defined(INFINITY_ADC2_SPS)
constexpr auto adc2_sps = INFINITY_ADC2_SPS;
constexpr auto adc2_num_samples = INFINITY_ADC2_NUM_SAMPLES;
constexpr auto adc2_num_channels = INFINITY_ADC2_NUM_CHANNELS;
constexpr auto adc2_buffer_size = adc2_num_samples * adc2_num_channels;
constexpr auto adc2_resolution = INFINITY_ADC2_RESOLUTION;
#endif

#if defined(INFINITY_DAC_RESOLUTION)
constexpr auto dac_resolution = INFINITY_DAC_RESOLUTION;
#endif

#endif
