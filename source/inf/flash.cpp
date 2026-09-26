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
   std::uint32_t flash::page_size(std::uintptr_t)
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

#elif defined(STM32F4)
namespace cycfi { namespace infinity
{
   namespace
   {
      // F4 sectors: 4 x 16 KB, then 64 KB, then 128 KB each.
      std::uint32_t sector_of(std::uintptr_t address)
      {
         std::uintptr_t offset = address - FLASH_BASE;
         if (offset < 0x10000)
            return offset / 0x4000;
         if (offset < 0x20000)
            return 4;
         return 5 + (offset - 0x20000) / 0x20000;
      }
   }

   std::uint32_t flash::page_size(std::uintptr_t address)
   {
      auto sector = sector_of(address);
      return sector < 4 ? 0x4000 : sector == 4 ? 0x10000 : 0x20000;
   }

   bool flash::erase_page(std::uintptr_t address)
   {
      FLASH_EraseInitTypeDef erase = {};
      erase.TypeErase = FLASH_TYPEERASE_SECTORS;
      erase.Sector = sector_of(address);
      erase.NbSectors = 1;
      erase.VoltageRange = FLASH_VOLTAGE_RANGE_3;
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
      for (std::size_t i = 0; ok && i != size; i += 4)
      {
         std::uint32_t word;
         std::memcpy(&word, p + i, sizeof(word));
         ok = HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, address + i,
            word) == HAL_OK;
      }
      HAL_FLASH_Lock();
      return ok;
   }
}}
#endif
