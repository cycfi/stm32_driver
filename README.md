# stm32_driver

Shared STM32 HAL/LL bridge and app hook layer for Cycfi firmware projects.

## Purpose

`stm32_driver` keeps reusable application code separate from STM32Cube-generated
board projects. The generated firmware owns clock, peripheral, GPIO, interrupt,
and DMA initialization; the application layer links this library and provides
the hook implementations it needs.

This lets board projects stay close to CubeMX output while C++ application and
test code can be reused across targets.

## What It Provides

- C hooks such as `setup()` and `loop()` for board startup integration.
- Weak interrupt and peripheral callbacks that applications can override.
- C++ GPIO port abstractions for STM32 LL GPIO access.
- Timing helpers backed by the STM32 HAL/LL tick utilities.
- MCU-family selection through the consuming project's CMake configuration.

## Integration Pattern

The board project sets the target MCU family before adding the library:

```cmake
set(STM32_MCU STM32F4)
add_compile_definitions(STM32F4 STM32F446xx)

add_subdirectory(path/to/stm32_driver stm32_driver)
target_link_libraries(app_target stm32_driver)
```

The generated `main.c` includes the driver hooks and calls into the application:

```c
#include <inf/driver.h>

setup();

while (1)
{
   loop();
}
```

Board-specific setup stays in the board project. Application code should use the
shared hooks and abstractions rather than directly depending on a specific MCU
target.
