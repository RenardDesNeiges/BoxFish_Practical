/******************************************************************************
 *
 * This module provides information about the project configuration
 * Copyright 2004, R O SoftWare
 * No guarantees, warrantees, or promises, implied or otherwise.
 * May be used for hobby or commercial purposes provided copyright
 * notice remains intact.
 *
 *****************************************************************************/
#ifndef INC_CONFIG_H
#define INC_CONFIG_H

#include <stdint.h>
#include "LPC21xx.h"

// some handy DEFINES
#ifndef FALSE
#define FALSE               0
#ifndef TRUE
#define TRUE                !FALSE
#endif
#endif

#ifndef BIT
#define BIT(n)              (1L << (n))
#endif

// declare functions and values from crt0.S & the linker control file
extern void reset(void);
// extern void exit(void);
// extern void abort(void);

#define WDOG()

// PLL setup values are computed within the LPC include file
// It relies upon the following defines
#define FOSC                (20000000)  // Master Oscillator Freq.
#define PLL_MUL             (3)         // PLL Multiplier
#define CCLK                (FOSC * PLL_MUL) // CPU Clock Freq.

// Pheripheral Bus Speed Divider
#define PBSD                2           // MUST BE 1, 2, or 4
#define PCLK                (CCLK / PBSD) // Pheripheal Bus Clock Freq.

// Do some value range testing
#if ((FOSC < 10000000) || (FOSC > 25000000))
#error Fosc out of range (10MHz-25MHz)
#error correct and recompile
#endif

#if ((CCLK < 10000000) || (CCLK > 60000000))
#error cclk out of range (10MHz-60MHz)
#error correct PLL_MUL and recompile
#endif

#if ((FCCO < 150000000) || (FCCO > 320000000))
#error Fcco out of range (156MHz-320MHz)
#error internal algorithm error
#endif

#if ((PBSD != 1) && (PBSD != 2) && (PBSD != 4))
#error Pheripheal Bus Speed Divider (PBSD) illegal value (1, 2, or 4)
#endif

#define TXD0_BIT            BIT(0)      // used by UART0
#define RXD0_BIT            BIT(1)      // used by UART0
#define LED1_BIT            BIT(12)     // P0.12 LED1

#endif
