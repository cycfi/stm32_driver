/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
// C interface barrier for the I2C slave role. Two layers, both generic:
//
// 1. Raw non-blocking (interrupt-driven) receive / transmit.
//
// 2. A register-file service (register-pointer model, the near-universal
//    I2C peripheral convention): the driver serves an array of 8-bit
//    registers; the master writes a 1-byte register address, then reads
//    (auto-incrementing) or writes single bytes. The register file's
//    layout and meaning belong to the application -- the driver only
//    moves bytes. Seed and configure the file first, then serve() to
//    start listening.
//
// The application includes inf/i2c_slave.hpp (the C++ facade), not this
// header. Implementation is board-specific, in Core/Src/i2c.c.
#if !defined(CYCFI_INFINITY_I2C_SLAVE_H_JULY_2_2026)
#define CYCFI_INFINITY_I2C_SLAVE_H_JULY_2_2026

#include <stdint.h>

// Storage ceiling for the served register file (a board's CMake can
// override).
#if !defined(INFINITY_I2C_SLAVE_MAX_REGS)
#define INFINITY_I2C_SLAVE_MAX_REGS 64
#endif

// This slave's own 7-bit bus address. The HAL APIs left-align it (addr << 1),
// which the driver does internally. A board can override.
#if !defined(INFINITY_I2C_SLAVE_ADDRESS)
#define INFINITY_I2C_SLAVE_ADDRESS 0x52
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Raw slave transfers, non-blocking. Arm a transfer, then the matching
// *_complete callback fires when it finishes; re-arm from there.
void i2c_slave_receive(uint8_t* data, uint16_t size);
void i2c_slave_receive_complete();    // Receive callback (app overrides)
void i2c_slave_transmit(uint8_t* data, uint16_t size);
void i2c_slave_transmit_complete();   // Transmit callback (app overrides)

// Register-file service. serve() starts listening, serving num_regs
// registers; read_to_clear() marks one register that resets to 0 after
// the master completes a read starting at it (an event/status bitmap).
void    i2c_slave_serve(uint16_t num_regs);
void    i2c_slave_read_to_clear(uint8_t reg);

// This slave's own 7-bit bus address (e.g. strap-composed at board init).
uint8_t i2c_slave_address(void);

// IRQ-safe application-side access to the served registers. set_regs
// updates a multi-byte field atomically; or_reg is an atomic OR for
// bitmap registers.
void    i2c_slave_set_reg(uint8_t reg, uint8_t value);
void    i2c_slave_set_regs(uint8_t reg, const uint8_t* data, uint16_t size);
void    i2c_slave_or_reg(uint8_t reg, uint8_t mask);
uint8_t i2c_slave_get_reg(uint8_t reg);

#ifdef __cplusplus
}
#endif

#endif
