/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
// C interface barrier for the multi-bus I2C master (blocking) + register-file
// access + wedged-bus recovery. The application includes inf/i2c_master.hpp
// (the C++ facade), not this header. Implementation currently in
// Core/Src/i2c.c.
#if !defined(CYCFI_INFINITY_I2C_MASTER_H_JULY_1_2026)
#define CYCFI_INFINITY_I2C_MASTER_H_JULY_1_2026

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Blocking master transfers (7-bit addr; the driver left-aligns for the HAL).
// Return 0 (HAL_OK) on success, non-zero on NAK / bus error.
int  i2c_master_transmit(uint16_t addr, uint8_t* data, uint16_t size);
int  i2c_master_receive(uint16_t addr, uint8_t* data, uint16_t size);

// Register-file access: write the 1-byte register, then read/write `size` bytes
// (repeated-start). bus 0 = I2CA, bus 1 = I2CB. addr is 7-bit.
int  i2c_master_reg_read(unsigned bus, uint16_t addr, uint8_t reg,
                         uint8_t* data, uint16_t size);
int  i2c_master_reg_write(unsigned bus, uint16_t addr, uint8_t reg,
                          uint8_t* data, uint16_t size);

// Free a wedged bus (SDA held low) by clocking it out + a STOP, then re-init
// the peripheral. For hot-plug recovery -- no MCU reset needed.
void i2c_master_bus_recover(unsigned bus);

#ifdef __cplusplus
}
#endif

#endif
