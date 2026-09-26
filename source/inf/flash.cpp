/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#include <inf/flash.hpp>
#include <inf/detail/hal.hpp>
#include <cstring>

#if defined(STM32G0) || defined(STM32C0)
namespace cycfi { namespace infinity
{
   std::uint32_t flash::page_size()
   {
      return FLASH_PAGE_SIZE;
   }

   bool flash::erase_page(std::uintptr_t address)
   {
      FLASH_EraseInitTypeDef erase = {};
      erase.TypeErase = FLASH_TYPEERASE_PAGES;
      erase.Banks = FLASH_BANK_1;
      erase.Page = (address - FLASH_BASE) / FLASH_PAGE_SIZE;
      erase.NbPages = 1;
      std::uint32_t failed = 0;
      HAL_FLASH_Unlock();
      bool ok = HAL_FLASHEx_Erase(&erase, &failed) == HAL_OK;
      HAL_FLASH_Lock();
      return ok;
   }

   bool flash::program(
      std::uintptr_t address, void const* data, std::size_t size)
   {
      if (address % 8 || size % 8)
         return false;
      auto const* p = static_cast<std::uint8_t const*>(data);
      bool ok = true;
      HAL_FLASH_Unlock();
      for (std::size_t i = 0; ok && i != size; i += 8)
      {
         std::uint64_t word;
         std::memcpy(&word, p + i, sizeof(word));
         ok = HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, address + i,
            word) == HAL_OK;
      }
      HAL_FLASH_Lock();
      return ok;
   }
}}
#endif
