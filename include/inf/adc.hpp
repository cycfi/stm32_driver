/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_ADC_HPP_JULY_2_2026)
#define CYCFI_INFINITY_ADC_HPP_JULY_2_2026

#include <inf/detail/adc.h>
#include <cstdint>
#include <cstddef>

// C++ facade over the polled, fixed-sequence multi-channel scan, plus the
// board ADC configuration constants.
namespace cycfi { namespace infinity
{
   // Board ADC configuration constants (from the board's INFINITY_* defines).
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

   struct adc
   {
      static int read_all(std::uint16_t* out)
      {
         return adc_read_all(out);
      }
   };
}}

// The streaming ADC DMA input hooks (global C ABI). The app defines the ones
// it needs (e.g. `void adc_in_half(...) { ... }`), overriding the weak no-op
// default. A copy of the barrier declaration in inf/detail/adc.h, surfaced
// here so the app sees the hook contract from this facade.
#if defined(INFINITY_HAS_ADC)
extern "C"
{
   void adc_in_half(volatile std::uint16_t* samples, std::size_t size);
   void adc_in_full(volatile std::uint16_t* samples, std::size_t size);
   void adc2_in(volatile std::uint16_t* samples, std::size_t size);
   void adc3_in(volatile std::uint16_t* samples, std::size_t size);
}
#endif

#endif
