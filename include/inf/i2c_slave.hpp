/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_I2C_SLAVE_HPP_JULY_2_2026)
#define CYCFI_INFINITY_I2C_SLAVE_HPP_JULY_2_2026

#include <inf/detail/i2c_slave.h>
#include <cstdint>

// C++ facade over the I2C slave role: raw receive/transmit plus the
// generic register-file service. Sibling of inf::i2c_master.

namespace cycfi { namespace infinity
{
   struct i2c_slave
   {
      // Raw non-blocking transfers
      static void receive(std::uint8_t* data, std::uint16_t size)
      {
         i2c_slave_receive(data, size);
      }

      static void transmit(std::uint8_t* data, std::uint16_t size)
      {
         i2c_slave_transmit(data, size);
      }

      // Register-file service
      static void serve(std::uint16_t num_regs)
      {
         i2c_slave_serve(num_regs);
      }

      static void read_to_clear(std::uint8_t reg)
      {
         i2c_slave_read_to_clear(reg);
      }

      static std::uint8_t address()
      {
         return i2c_slave_address();
      }

      static void set_reg(std::uint8_t reg, std::uint8_t value)
      {
         i2c_slave_set_reg(reg, value);
      }

      static void set_regs(
         std::uint8_t reg, std::uint8_t const* data, std::uint16_t size)
      {
         i2c_slave_set_regs(reg, data, size);
      }

      static void or_reg(std::uint8_t reg, std::uint8_t mask)
      {
         i2c_slave_or_reg(reg, mask);
      }

      static std::uint8_t get_reg(std::uint8_t reg)
      {
         return i2c_slave_get_reg(reg);
      }
   };
}}

// The slave transfer-completion hooks (global C ABI). The app defines the
// ones it needs (e.g. `void i2c_slave_receive_complete() { ... }`),
// overriding the weak no-op default. A copy of the barrier declaration in
// inf/detail/i2c_slave.h, surfaced here so the app sees the hook contract
// from this facade.
extern "C"
{
   void i2c_slave_receive_complete();
   void i2c_slave_transmit_complete();
}

#endif
