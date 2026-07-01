/*=============================================================================
   Copyright (c) 2014-2023 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_SUPPORT_HPP_DECEMBER_20_2015)
#define CYCFI_INFINITY_SUPPORT_HPP_DECEMBER_20_2015

#include <type_traits>
#include <cstdint>
#include <cstring>
#include <inf/clock.hpp>     // millis / delay_ms / clock_speed (no HAL here)

namespace cycfi { namespace infinity
{
   ////////////////////////////////////////////////////////////////////////////
   // Basic metaprogramming utils
   ////////////////////////////////////////////////////////////////////////////
   template <bool b>
   using bool_ = std::integral_constant<bool, b>;

   template <int i>
   using int_ = std::integral_constant<int, i>;

   template <std::size_t i>
   using uint_ = std::integral_constant<std::size_t, i>;

   template <int8_t i>
   using int8_ = std::integral_constant<std::int8_t, i>;

   template <uint8_t i>
   using uint8_ = std::integral_constant<std::uint8_t, i>;

   template <int16_t i>
   using int16_ = std::integral_constant<std::int16_t, i>;

   template <uint16_t i>
   using uint16_ = std::integral_constant<std::uint16_t, i>;

   template <int32_t i>
   using int32_ = std::integral_constant<std::int32_t, i>;

   template <uint32_t i>
   using uint32_ = std::integral_constant<std::uint32_t, i>;

   template <int64_t i>
   using int64_ = std::integral_constant<std::int64_t, i>;

   template <uint64_t i>
   using uint64_ = std::integral_constant<std::uint64_t, i>;

   template <typename T>
   struct identity
   {
      using type = T;
   };

   ////////////////////////////////////////////////////////////////////////////
   // error_handler
   ////////////////////////////////////////////////////////////////////////////
   void error_handler();

   ////////////////////////////////////////////////////////////////////////////
   // debounce
   ////////////////////////////////////////////////////////////////////////////
   inline bool debounce(uint32_t& time, uint32_t delay)
   {
      auto now = millis();
      auto elapsed = now - time;
      time = now;
      if (elapsed < delay)
         return false;
      return true;
   }
}}

#endif
