stm32/ — platform-specific, MCU-specific driver sources
=======================================================

This directory holds the STM32-family-specific implementation that sits behind
the portable `inf/` API. Keep the split clean:

  - Portable, MCU-agnostic layer ... include/inf/  +  source/inf/
        (driver.h / driver.hpp hooks, port.hpp, support.hpp, driver.c)
  - Platform / MCU-specific layer .. stm32/        (this directory)

Everything under stm32/ may depend on a specific STM32 family's HAL/LL headers
and on CubeMX-generated handle names; nothing in include/inf/ or source/inf/
should.

Layout
------
  src/<family>/   one subdirectory per supported STM32 family:
      stm32c0/
      stm32f4/
      stm32h7/

Each family subdirectory contains that family's sources (the LL utility units
today, plus any peripheral glue that needs the family's HAL/LL).

Family selection
----------------
The consuming board project sets STM32_MCU before adding this library; the
top-level CMakeLists.txt compiles the matching family's sources only:

    set(STM32_MCU STM32H7)        # selects stm32/src/stm32h7/
    add_subdirectory(path/to/stm32_driver stm32_driver)
    target_link_libraries(app_target stm32_driver)

Supported STM32_MCU values: STM32C0, STM32F4, STM32H7.

Adding a peripheral driver
--------------------------
  1. Declare the portable hooks/API in include/inf/ (driver.h for C hooks),
     gated by the INFINITY_HAS_<PERIPH> macro the board opts into.
  2. Put the family-specific implementation here under stm32/src/<family>/ and
     add the file to that family's source list in CMakeLists.txt.
  3. When the implementation needs a CubeMX handle, take it from the board via
     an INFINITY_<PERIPH>_HANDLE define (e.g. INFINITY_DAC_HANDLE=hdac) instead
     of hard-coding the generated name.

Example — Ethernet (not yet implemented): add an INFINITY_HAS_ETH gate and ETH
hooks in include/inf/driver.h, put the RMII/MDIO + PHY driver implementation in
stm32/src/stm32h7/, and pass the MAC handle via INFINITY_ETH_HANDLE=heth.

Adding a new MCU family
-----------------------
Create stm32/src/<family>/, add a matching STM32_MCU branch in CMakeLists.txt,
and provide that family's LL utility / peripheral sources.
