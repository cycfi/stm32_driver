/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
// C interface barrier for the raw-L2 (no IP) Ethernet data link and its PHY.
// The application never includes this directly -- it includes inf/ethernet.hpp,
// which wraps these symbols in a C++ facade. The implementations currently live
// in the board project (Core/Src/eth_link.c, dp83tc817s.c); they move behind
// this barrier into lib/stm32_driver in a later step.
#if !defined(CYCFI_INFINITY_ETHERNET_H_JULY_1_2026)
#define CYCFI_INFINITY_ETHERNET_H_JULY_1_2026

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// --- raw-L2 data link --------------------------------------------------------
// Register RX callbacks and start the MAC DMA (after PHY config).
void eth_link_start(void);

// Send one raw L2 frame carrying `len` payload bytes.
void eth_link_send(const uint8_t* payload, uint16_t len);

// Poll the RX path; dispatches received frames to eth_link_on_rx().
void eth_link_poll_rx(void);

// Start the 50 kHz TX pacing timer -> eth_tx_tick() from its ISR.
void eth_tx_timer_start(void);

// --- inbound hooks (the application defines these; weak no-op default in the
// transport). The application defines them as ordinary C++ functions -- their C
// linkage is inherited from these declarations, so no `extern "C"` is written in
// application code.
void eth_link_on_rx(const uint8_t* payload, uint16_t len);  // one per RX frame
void eth_tx_tick(void);                                     // 50 kHz TX pacing

// --- PHY status (100BASE-T1) -------------------------------------------------
int      dp83tc817s_link_up(void);   // 1 up, 0 down, -1 no PHY
int      dp83tc817s_sqi(void);       // 0 (worst)..7 (best), -1 no PHY
uint16_t dp83tc817s_phyid1(void);    // PHYIDR1 (0x2000 = TI family, 0xFFFF none)

#ifdef __cplusplus
}
#endif

#endif
