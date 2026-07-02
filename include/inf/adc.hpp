/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_ADC_HPP_JULY_2_2026)
#define CYCFI_INFINITY_ADC_HPP_JULY_2_2026

#include <inf/adc.h>
#include <cstdint>

// C++ facade over the polled, fixed-sequence multi-channel ADC scan.

namespace cycfi { namespace infinity
{
   struct adc
   {
      static int read_all(std::uint16_t* out)
      {
         return adc_read_all(out);
      }
   };
}}

#endif
