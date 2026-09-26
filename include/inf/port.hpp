/*=============================================================================
   Copyright (c) 2014-2023 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_PORT_HPP_DECEMBER_20_2015)
#define CYCFI_INFINITY_PORT_HPP_DECEMBER_20_2015

#include <inf/detail/port_impl.hpp>
// #include <inf/config.hpp>
// #include <inf/support.hpp>

namespace cycfi { namespace infinity
{
   namespace port
   {
      constexpr uint16_t porta = 0;
      constexpr uint16_t portb = 1;
      constexpr uint16_t portc = 2;
      constexpr uint16_t portd = 3;
      constexpr uint16_t porte = 4;
      constexpr uint16_t portf = 5;
      constexpr uint16_t portg = 6;
      constexpr uint16_t porth = 7;
      constexpr uint16_t porti = 8;
   }

   template <typename T>
   struct inverse_port
   {
      operator bool() const
      {
         return pin.off();
      }

      T operator!() const
      {
         return pin;
      }

      T pin;
   };

   struct on_type
   {
      operator bool() const
      {
         return true;
      }

      bool operator!() const
      {
         return false;
      }
   };

   struct off_type
   {
      operator bool() const
      {
         return false;
      }

      bool operator!() const
      {
         return true;
      }
   };

   namespace port
   {
      constexpr on_type on = {};
      constexpr off_type off = {};
   }

   ////////////////////////////////////////////////////////////////////////////
   // output_port
   ////////////////////////////////////////////////////////////////////////////
   template <std::size_t port, std::size_t pin>
   struct output_port
   {
      static constexpr uint32_t  mask = 1 << pin;

      // there are only 9 ports
      static_assert(port < 9, "Invalid port");
      // there are only 16 pins per port
      static_assert(pin < 16, "Invalid pin");

      using self_type = output_port;
      using inverse_type = inverse_port<output_port>;

      output_port() = default;
      output_port(output_port const&) = default;

      GPIO_TypeDef& gpio() const
      {
         return detail::get_port<port>();
      }

      volatile uint32_t& ref() const
      {
         return gpio().ODR;
      }

      bool state() const
      {
         return (ref() & mask) != 0;
      }

      inverse_type operator!() const
      {
         return { *this };
      }

      output_port& operator=(bool val)
      {
         ref() ^= (-uint16_t(val) ^ ref()) & mask;
         return *this;
      }

      output_port& operator=(self_type)
      {
         return *this;
      }

      output_port& operator=(inverse_type)
      {
         ref() ^= mask;
         return *this;
      }

      output_port& operator=(on_type)
      {
         ref() |= mask;
         return *this;
      }

      output_port& operator=(off_type)
      {
         ref() &= ~mask;
         return *this;
      }
   };

   ////////////////////////////////////////////////////////////////////////////
   // input_port
   ////////////////////////////////////////////////////////////////////////////
   template <std::size_t port, std::size_t pin>
   struct input_port
   {
      static constexpr uint32_t  mask = 1 << pin;

      // there are only 9 ports
      static_assert(port < 9, "Invalid port");
      // there are only 16 pins per port
      static_assert(port < 16, "Invalid pin");

      using self_type = input_port;

      input_port() = default;
      input_port(input_port const&) = default;

      GPIO_TypeDef& gpio() const
      {
         return detail::get_port<port>();
      }

      auto& ref() const
      {
         return gpio().IDR;
      }

      bool state() const
      {
         return (ref() & mask) != 0;
      }

      operator bool() const
      {
         return state();
      }

      bool operator!() const
      {
         return !state();
      }
   };

   ////////////////////////////////////////////////////////////////////////////
   // pin_mode: switch a pin at run time between analog (the ADC's mode,
   // no pull) and a digital input with the weak pull-up or pull-down, for
   // example to probe whether anything drives an analog input. The port
   // and pin are the runtime counterparts of output_port's parameters.
   // Read-modify-write of the port's MODER and PUPDR: call from one
   // context only.
   ////////////////////////////////////////////////////////////////////////////
   namespace port
   {
      enum class mode { analog, pull_up, pull_down };

      inline void pin_mode(std::size_t port, std::size_t pin, mode m)
      {
         constexpr auto stride = GPIOB_BASE - GPIOA_BASE;
         auto& gpio = *reinterpret_cast<GPIO_TypeDef*>(
            GPIOA_BASE + port * stride);
         auto shift = pin * 2;
         std::uint32_t moder = m == mode::analog ? 0x3 : 0x0;
         std::uint32_t pupdr =
            m == mode::pull_up ? 0x1 : m == mode::pull_down ? 0x2 : 0x0;
         gpio.MODER = (gpio.MODER & ~(0x3u << shift)) | (moder << shift);
         gpio.PUPDR = (gpio.PUPDR & ~(0x3u << shift)) | (pupdr << shift);
      }
   }
}}

// The EXTI GPIO interrupt hook (global C ABI). The app defines
// `void gpio_interrupt(int pin) { ... }`, overriding the weak no-op default.
// A copy of the barrier declaration in inf/detail/gpio.h, surfaced here so
// the app sees the hook contract from this facade (pin I/O and its interrupt
// live together).
#if defined(INFINITY_HAS_GPIO_INTERRUPT)
extern "C" void gpio_interrupt(int pin);
#endif

#endif
