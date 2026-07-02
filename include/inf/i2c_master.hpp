/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_I2C_MASTER_HPP_JULY_1_2026)
#define CYCFI_INFINITY_I2C_MASTER_HPP_JULY_1_2026

#include <inf/detail/i2c_master.h>
#include <cstdint>

// C++ facade over the multi-bus I2C master. bus is a small index (0 = I2CA,
// 1 = I2CB); all calls return 0 (HAL_OK) on success, non-zero on error.

namespace cycfi { namespace infinity
{
   struct i2c_master
   {
      static int reg_read(unsigned bus, std::uint16_t addr, std::uint8_t reg,
                          std::uint8_t* data, std::uint16_t size)
      {
         return i2c_master_reg_read(bus, addr, reg, data, size);
      }

      static int reg_write(unsigned bus, std::uint16_t addr, std::uint8_t reg,
                           std::uint8_t* data, std::uint16_t size)
      {
         return i2c_master_reg_write(bus, addr, reg, data, size);
      }

      static void bus_recover(unsigned bus)
      {
         i2c_master_bus_recover(bus);
      }

      static int transmit(std::uint16_t addr, std::uint8_t* data,
                          std::uint16_t size)
      {
         return i2c_master_transmit(addr, data, size);
      }

      static int receive(std::uint16_t addr, std::uint8_t* data,
                         std::uint16_t size)
      {
         return i2c_master_receive(addr, data, size);
      }
   };
}}

#endif
