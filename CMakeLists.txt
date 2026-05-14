###############################################################################
#  Copyright (c) 2016-2022 Joel de Guzman
###############################################################################
project(stm32_driver C CXX ASM)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

message(STATUS "STM32 MCU: ${STM32_MCU}")

if (${STM32_MCU} STREQUAL "STM32H7")
   set(STM32_DRIVER_SOURCES
      stm32/src/stm32h7/stm32h7xx_ll_utils.c
   )
elseif (${STM32_MCU} STREQUAL "STM32F4")
   set(STM32_DRIVER_SOURCES
      stm32/src/stm32f4/stm32f4xx_ll_utils.c
   )
elseif (${STM32_MCU} STREQUAL "STM32C0")
   set(STM32_DRIVER_SOURCES
      stm32/src/stm32c0/stm32c0xx_ll_utils.c
   )
endif()

set(STM32_INF_SOURCES
   ${CMAKE_CURRENT_SOURCE_DIR}/source/inf/driver.c
)

add_library(stm32_driver
   STATIC ${STM32_DRIVER_SOURCES} ${STM32_INF_SOURCES}
)

target_include_directories(stm32_driver PUBLIC include)
