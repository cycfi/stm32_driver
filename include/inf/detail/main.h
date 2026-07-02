/*=============================================================================
   Copyright (c) 2014-2026 Cycfi Research. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
// C interface barrier for the application entry hooks. The app defines
// setup() (once, at boot) and loop() (repeatedly); the board's generated
// main() calls them. Weak no-op defaults live in source/inf/driver.c. The
// app defines them as plain functions -- C linkage is inherited from these
// declarations, so no `extern "C"` is written in app code.
#if !defined(CYCFI_INFINITY_MAIN_H_JULY_2_2026)
#define CYCFI_INFINITY_MAIN_H_JULY_2_2026

#ifdef __cplusplus
extern "C" {
#endif

void setup();
void loop();

#ifdef __cplusplus
}
#endif

#endif
