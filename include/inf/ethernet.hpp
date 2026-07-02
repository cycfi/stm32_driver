/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_INFINITY_ETHERNET_HPP_JULY_1_2026)
#define CYCFI_INFINITY_ETHERNET_HPP_JULY_1_2026

#include <inf/detail/ethernet.h>
#include <cstdint>

// C++ facade over the raw-L2 Ethernet data link + PHY. This is what an
// application includes; it never touches the C symbols or the HAL directly.

namespace cycfi { namespace infinity
{
   ////////////////////////////////////////////////////////////////////////////
   // Raw-L2 data link: send frames, poll RX, and start the TX pacing timer.
   ////////////////////////////////////////////////////////////////////////////
   struct eth_link
   {
      static void start_tx_timer()
      {
         eth_tx_timer_start();
      }

      static void send(std::uint8_t const* data, std::uint16_t len)
      {
         eth_link_send(data, len);
      }

      static void poll_rx()
      {
         eth_link_poll_rx();
      }
   };

   ////////////////////////////////////////////////////////////////////////////
   // 100BASE-T1 PHY link status.
   ////////////////////////////////////////////////////////////////////////////
   struct phy
   {
      static bool link_up()  { return dp83tc817s_link_up() == 1; }
      static int  sqi()      { return dp83tc817s_sqi(); }
   };
}}

////////////////////////////////////////////////////////////////////////////
// RX + TX hooks (global C ABI). The app defines these (e.g.
// `void eth_tx_tick() { ... }`), overriding the weak no-op default. A copy of
// the barrier declaration in inf/detail/ethernet.h, surfaced here so the app
// sees the hook contract from this facade.
////////////////////////////////////////////////////////////////////////////
extern "C"
{
   void eth_link_on_rx(std::uint8_t const* payload, std::uint16_t len);
   void eth_tx_tick();
}

#endif
