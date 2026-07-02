/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_DAC_HPP_JULY_2_2026)
#define CYCFI_INFINITY_DAC_HPP_JULY_2_2026

#include <inf/detail/dac.h>
#include <cstdint>

// C++ facade over the DAC outputs.
namespace cycfi { namespace infinity
{
   // DAC resolution (bits), when the board provides one.
#if defined(INFINITY_DAC_RESOLUTION)
   constexpr auto dac_resolution = INFINITY_DAC_RESOLUTION;
#endif

#if defined(INFINITY_HAS_DAC)
   struct dac
   {
      static void out1(std::uint16_t sample) { dac1_out(sample); }
      static void out2(std::uint16_t sample) { dac2_out(sample); }
   };
#endif
}}

#endif
