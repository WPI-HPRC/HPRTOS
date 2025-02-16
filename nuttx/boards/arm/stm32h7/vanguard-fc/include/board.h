/****************************************************************************
 * boards/arm/stm32h7/vanguard-fc/include/board.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#pragma once

#include <nuttx/config.h>

#ifndef __ASSEMBLY__
#include <stdint.h>
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Clocking *****************************************************************/

/* The Vanguard Flight Computer provides the following clock sources:
 *
 *   MCO: 25 MHz HSE
 *   X2:  32.768 KHz crystal for LSE
 *
 * So we have these clock source available within the STM32
 *
 *   HSI: 16 MHz RC factory-trimmed
 *   LSI: 32 KHz RC
 *   HSE: 25 MHz crystal
 */

#define STM32_BOARD_XTAL 25000000ul

#define STM32_HSI_FREQUENCY 16000000ul
#define STM32_LSI_FREQUENCY 32000
#define STM32_HSE_FREQUENCY STM32_BOARD_XTAL

/* Main PLL Configuration
 *
 * PLL source is HSE = 25,000,000
 *
 * PLL_VCOx = (STM32_HSE_FREQUENCY / PLLM) * PLLN
 *
 * Subject To:
 *  1 <= PLLM <= 63
 *  4 <= PLLN <= 512
 *
 *  150MHz <= PLL_VCOL <= 420MHz
 *  192MHz <= PLL_VCOH <= 836MHz
 *
 *
 *  SYSCLK = PLL_VCO / PLLP
 *  CPUCLK = SYSCLK / D1CPRE
 *
 */

#define STM32_BOAED_USEHSE

#define STM32_PLLCFG_PLLSRC RCC_PLLCKSELR_PLLSRC_HSE

/* PLL1, wide 4 - 8 MHz input, enable DIVP, DIVQ, DIVR
 *
 *   PLL1_VCO = (25 MHz / 5) * 192 = 960 MHz
 *
 *   PLL1P = PLL1_VCO/2  = 960 MHz / 2   = 480 MHz
 *   PLL1Q = PLL1_VCO/4  = 960 MHz / 15  = 64 MHz
 *   PLL1R = PLL1_VCO/8  = 960 MHz / 2   = 480 MHz
 */

#define STM32_PLLCFG_PLL1CFG     (RCC_PLLCFGR_PLL1VCOSEL_WIDE | \
                                  RCC_PLLCFGR_PLL1RGE_4_8_MHZ | \
                                  RCC_PLLCFGR_DIVP1EN | \
                                  RCC_PLLCFGR_DIVQ1EN | \
                                  RCC_PLLCFGR_DIVR1EN)

#define STM32_VCO1_FREQUENCY ((STM32_HSE_FREQUENCY / 5 ) * 192)
#define STM32_PLL1P_FREQUENCY (STM32_VCO1_FREQUENCY / 2)
#define STM32_PLL1Q_FREQUENCY (STM32_VCO1_FREQUENCY / 15)
#define STM32_PLL1R_FREQUENCY (STM32_VCO1_FREQUENCY / 2)

#define STM32_PLLCFG_PLL1M       RCC_PLLCKSELR_DIVM1(5)
#define STM32_PLLCFG_PLL1N       RCC_PLL1DIVR_N1(192)
#define STM32_PLLCFG_PLL1P       RCC_PLL1DIVR_P1(2)
#define STM32_PLLCFG_PLL1Q       RCC_PLL1DIVR_Q1(15)
#define STM32_PLLCFG_PLL1R       RCC_PLL1DIVR_R1(2)

/* PLL2, wide 4 - 8 MHz input, enable DIVP, DIVQ, DIVR
 *
 *   PLL1_VCO = (25 MHz / 32) * 129 = 600 MHz
 *
 *   PLL2P = PLL2_VCO/2  = 600 MHz / 8   = 75 MHz
 *   PLL2Q = PLL2_VCO/4  = 600 MHz / 40  = 15 MHz
 *   PLL2R = PLL2_VCO/8  = 600 MHz / 3   = 200 MHz
 */

#define STM32_PLLCFG_PLL2CFG (RCC_PLLCFGR_PLL2VCOSEL_WIDE | \
                              RCC_PLLCFGR_PLL2RGE_4_8_MHZ | \
                              RCC_PLLCFGR_DIVP2EN | \
                              RCC_PLLCFGR_DIVQ2EN | \
                              RCC_PLLCFGR_DIVR2EN )

#define STM32_VCO2_FREQUENCY     ((STM32_HSE_FREQUENCY / 32) * 129)  // 600 MHz
#define STM32_PLL2P_FREQUENCY    (STM32_VCO2_FREQUENCY / 2)  // 100 MHz (Valid for SPI123)
#define STM32_PLL2Q_FREQUENCY    (STM32_VCO2_FREQUENCY / 2) // 15 MHz (unchanged)
#define STM32_PLL2R_FREQUENCY    (STM32_VCO2_FREQUENCY / 2)  // 200 MHz (unchanged)

#define STM32_PLLCFG_PLL2M       RCC_PLLCKSELR_DIVM2(32)
#define STM32_PLLCFG_PLL2N       RCC_PLL2DIVR_N2(129)
#define STM32_PLLCFG_PLL2P       RCC_PLL2DIVR_P2(8)
#define STM32_PLLCFG_PLL2Q       RCC_PLL2DIVR_Q2(2)
#define STM32_PLLCFG_PLL2R       RCC_PLL2DIVR_R2(2)

#define STM32_PLLCFG_PLL3CFG (RCC_PLLCFGR_PLL3VCOSEL_WIDE | \
                              RCC_PLLCFGR_PLL3RGE_4_8_MHZ | \
                              RCC_PLLCFGR_DIVP3EN | \
                              RCC_PLLCFGR_DIVQ3EN | \
                              RCC_PLLCFGR_DIVR3EN )

#define STM32_VCO3_FREQUENCY     ((STM32_HSE_FREQUENCY / 2) * 12)  // 600 MHz
#define STM32_PLL3P_FREQUENCY    (STM32_VCO3_FREQUENCY / 2)  // 100 MHz (Valid for SPI123)
#define STM32_PLL3Q_FREQUENCY    (STM32_VCO3_FREQUENCY / 2) // 15 MHz (unchanged)
#define STM32_PLL3R_FREQUENCY    (STM32_VCO3_FREQUENCY / 2)  // 200 MHz (unchanged)

#define STM32_PLLCFG_PLL3M       RCC_PLLCKSELR_DIVM3(2)
#define STM32_PLLCFG_PLL3N       RCC_PLL3DIVR_N3(12)
#define STM32_PLLCFG_PLL3P       RCC_PLL3DIVR_P3(2)
#define STM32_PLLCFG_PLL3Q       RCC_PLL3DIVR_Q3(2)
#define STM32_PLLCFG_PLL3R       RCC_PLL3DIVR_R3(2)

#define STM32_RCC_D1CFGR_D1CPRE  (RCC_D1CFGR_D1CPRE_SYSCLK)
#define STM32_SYSCLK_FREQUENCY   (STM32_PLL1P_FREQUENCY)
#define STM32_CPUCLK_FREQUENCY   (STM32_SYSCLK_FREQUENCY / 1)

/* Configure Clock Assignments */

/* AHB clock (HCLK) is SYSCLK/2 (480 MHz max)
 * HCLK1 = HCLK2 = HCLK3 = HCLK4
 */

#define STM32_RCC_D1CFGR_HPRE   RCC_D1CFGR_HPRE_SYSCLKd2        /* HCLK  = SYSCLK / 2 */
#define STM32_ACLK_FREQUENCY    (STM32_SYSCLK_FREQUENCY / 2)    /* ACLK in D1, HCLK3 in D1 */
#define STM32_HCLK_FREQUENCY    (STM32_SYSCLK_FREQUENCY / 2)    /* HCLK in D2, HCLK4 in D3 */


/* APB1 clock (PCLK1) is HCLK/2 (120 MHz) */

#define STM32_RCC_D2CFGR_D2PPRE1  RCC_D2CFGR_D2PPRE1_HCLKd2       /* PCLK1 = HCLK / 2 */
#define STM32_PCLK1_FREQUENCY     (STM32_HCLK_FREQUENCY/2)

/* APB2 clock (PCLK2) is HCLK/2 (120 MHz) */

#define STM32_RCC_D2CFGR_D2PPRE2  RCC_D2CFGR_D2PPRE2_HCLKd2       /* PCLK2 = HCLK / 2 */
#define STM32_PCLK2_FREQUENCY     (STM32_HCLK_FREQUENCY/2)

/* APB3 clock (PCLK3) is HCLK/2 (120 MHz) */

#define STM32_RCC_D1CFGR_D1PPRE   RCC_D1CFGR_D1PPRE_HCLKd2        /* PCLK3 = HCLK / 2 */
#define STM32_PCLK3_FREQUENCY     (STM32_HCLK_FREQUENCY/2)

/* APB4 clock (PCLK4) is HCLK/2 (120 MHz) */

#define STM32_RCC_D3CFGR_D3PPRE   RCC_D3CFGR_D3PPRE_HCLKd2       /* PCLK4 = HCLK / 2 */
#define STM32_PCLK4_FREQUENCY     (STM32_HCLK_FREQUENCY/2)


/* Timer clock frequencies */

/* Timers driven from APB1 will be twice PCLK1 */

#define STM32_APB1_TIM2_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM3_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM4_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM5_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM6_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM7_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM12_CLKIN  (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM13_CLKIN  (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM14_CLKIN  (2*STM32_PCLK1_FREQUENCY)

/* Timers driven from APB2 will be twice PCLK2 */

#define STM32_APB2_TIM1_CLKIN   (2*STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM8_CLKIN   (2*STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM15_CLKIN  (2*STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM16_CLKIN  (2*STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM17_CLKIN  (2*STM32_PCLK2_FREQUENCY)


/* Kernel Clock Configuration
 *
 * Note: look at Table 54 in ST Manual
 */

/* I2C123 clock source - HSI */

#define STM32_RCC_D2CCIP2R_I2C123SRC RCC_D2CCIP2R_I2C123SEL_HSI

/* I2C4 clock source - HSI */

#define STM32_RCC_D3CCIPR_I2C4SRC    RCC_D3CCIPR_I2C4SEL_HSI

/* SPI123 clock source - PLL1Q */

#define STM32_RCC_D2CCIP1R_SPI123SRC RCC_D2CCIP1R_SPI123SEL_PLL1

/* SPI45 clock source - APB (PCLK2?) */

#define STM32_RCC_D2CCIP1R_SPI45SRC  RCC_D2CCIP1R_SPI45SEL_APB

/* SPI6 clock source - APB (PCLK4) */

#define STM32_RCC_D3CCIPR_SPI6SRC    RCC_D3CCIPR_SPI6SEL_PCLK4

/* USB 1 and 2 clock source - HSI48 */

#define STM32_RCC_D2CCIP2R_USBSRC    RCC_D2CCIP2R_USBSEL_HSI48

/* ADC 1 2 3 clock source - pll2_pclk */

#define STM32_RCC_D3CCIPR_ADCSRC     RCC_D3CCIPR_ADCSEL_PLL2


/* FLASH wait states
 *
 *  ------------ ---------- -----------
 *  Vcore        MAX ACLK   WAIT STATES
 *  ------------ ---------- -----------
 *  1.15-1.26 V     70 MHz    0
 *  (VOS1 level)   140 MHz    1
 *                 210 MHz    2
 *  1.05-1.15 V     55 MHz    0
 *  (VOS2 level)   110 MHz    1
 *                 165 MHz    2
 *                 220 MHz    3
 *  0.95-1.05 V     45 MHz    0
 *  (VOS3 level)    90 MHz    1
 *                 135 MHz    2
 *                 180 MHz    3
 *                 225 MHz    4
 *  ------------ ---------- -----------
 */

#define BOARD_FLASH_WAITSTATES 4

/* SDMMC definitions ********************************************************/

/* Init 400 kHz, PLL1Q/(2*300) = 240 MHz / (2*300) = 400 Khz */

#define STM32_SDMMC_INIT_CLKDIV     (300 << STM32_SDMMC_CLKCR_CLKDIV_SHIFT)

/* Just set these to 24 MHz for now,
 * PLL1Q/(2*5) = 240 MHz / (2*5) = 24 MHz
 */

#define STM32_SDMMC_MMCXFR_CLKDIV   (5 << STM32_SDMMC_CLKCR_CLKDIV_SHIFT)
#define STM32_SDMMC_SDXFR_CLKDIV    (5 << STM32_SDMMC_CLKCR_CLKDIV_SHIFT)

#define STM32_SDMMC_CLKCR_EDGE      STM32_SDMMC_CLKCR_NEGEDGE

/* LED definitions **********************************************************/

/* The board has 1 user LED RGB that could be used this diagnostic LED too.
 * LED RED    PG2
 * LED GREEN  PG3
 * LED BLUE   PB2
 *
 * If CONFIG_ARCH_LEDS is not defined, then the user can control the LEDs in
 * any way.
 * The following definitions are used to access individual LEDs.
 */

/* LED index values for use with board_userled() */

#define BOARD_LED1        0
#define BOARD_LED2        1
#define BOARD_LED3        2
#define BOARD_NLEDS       3

#define BOARD_LED_RED      BOARD_LED1
#define BOARD_LED_GREEN    BOARD_LED2
#define BOARD_LED_BLUE     BOARD_LED3

/* LED bits for use with board_userled_all() */

#define BOARD_LED1_BIT    (1 << BOARD_LED1)
#define BOARD_LED2_BIT    (1 << BOARD_LED2)
#define BOARD_LED3_BIT    (1 << BOARD_LED3)

/* If CONFIG_ARCH_LEDS is defined, the usage by the board port is defined in
 * include/board.h and src/stm32_leds.c.
 * The LEDs are used to encode OS-related events as follows:
 *
 *
 *   SYMBOL                     Meaning                      LED state
 *                                                        Red   Green Blue
 *   ----------------------  --------------------------  ------ ------ ---
 */

#define LED_STARTED        0 /* NuttX has been started   OFF    OFF   OFF  */
#define LED_HEAPALLOCATE   1 /* Heap has been allocated  OFF    OFF   ON   */
#define LED_IRQSENABLED    2 /* Interrupts enabled       OFF    ON    OFF  */
#define LED_STACKCREATED   3 /* Idle stack created       OFF    ON    ON   */
#define LED_INIRQ          4 /* In an interrupt          N/C    N/C   GLOW */
#define LED_SIGNAL         5 /* In a signal handler      N/C    GLOW  N/C  */
#define LED_ASSERTION      6 /* An assertion failed      GLOW   N/C   GLOW */
#define LED_PANIC          7 /* The system has crashed   Blink  OFF   N/C  */
#define LED_IDLE           8 /* MCU is is sleep mode     ON     OFF   OFF  */

/* Thus if the Green LED is statically on, NuttX has successfully booted and
 * is, apparently, running normally.  If the Red LED is flashing at
 * approximately 2Hz, then a fatal error has been detected and the system
 * has halted.
 */

/* Alternate function pin selections ****************************************/

/* USART1 (Serial Console) */

#define GPIO_USART1_RX   (GPIO_USART1_RX_1 | GPIO_SPEED_100MHz)  /* PB15 */
#define GPIO_USART1_TX   (GPIO_USART1_TX_1 | GPIO_SPEED_100MHz)  /* PB14 */

/* OTGFS */

#define GPIO_OTGFS_DM  (GPIO_OTGFS_DM_0  | GPIO_SPEED_100MHz) /* PA11 */
#define GPIO_OTGFS_DP  (GPIO_OTGFS_DP_0  | GPIO_SPEED_100MHz) /* PA12 */
#define GPIO_OTGFS_ID  (GPIO_OTGFS_ID_0  | GPIO_SPEED_100MHz)    /* PA10 */

/* TIM1 */

#define GPIO_TIM1_CH1OUT  (GPIO_TIM1_CH1OUT_2|GPIO_SPEED_50MHz)  /* PE9  - D6 */
#define GPIO_TIM1_CH1NOUT (GPIO_TIM1_CH1NOUT_3|GPIO_SPEED_50MHz) /* PE8  - D42 */
#define GPIO_TIM1_CH2OUT  (GPIO_TIM1_CH2OUT_2|GPIO_SPEED_50MHz)  /* PE11 - D5 */
#define GPIO_TIM1_CH2NOUT (GPIO_TIM1_CH2NOUT_3|GPIO_SPEED_50MHz) /* PE10 - D40 */

#define GPIO_TIM1_CH1IN   (GPIO_TIM1_CH1IN_2|GPIO_SPEED_50MHz)   /* PE9 */
#define GPIO_TIM1_CH2IN   (GPIO_TIM1_CH2IN_2|GPIO_SPEED_50MHz)   /* PE11 */

/* TIM3 */

#define GPIO_TIM3_CH1OUT  (GPIO_TIM3_CH1OUT_2|GPIO_SPEED_50MHz)  /* PB4  */
#define GPIO_TIM3_CH2OUT  (GPIO_TIM3_CH2OUT_2|GPIO_SPEED_50MHz)  /* PB5  */

#define GPIO_TIM3_CH1IN   (GPIO_TIM3_CH1IN_2|GPIO_SPEED_50MHz)   /* PA4 */
#define GPIO_TIM3_CH2IN   (GPIO_TIM3_CH2IN_2|GPIO_SPEED_50MHz)   /* PB5 */

/* TIM4 */

#define GPIO_TIM4_CH1IN   (GPIO_TIM4_CH1IN_2|GPIO_SPEED_50MHz)   /* PD12 */
#define GPIO_TIM4_CH2IN   (GPIO_TIM4_CH2IN_2|GPIO_SPEED_50MHz)   /* PD13 */

/* I2C1 Use Nucleo I2C1 pins */

#define GPIO_I2C1_SCL     (GPIO_I2C1_SCL_1|GPIO_SPEED_50MHz)     /* PB6 */
#define GPIO_I2C1_SDA     (GPIO_I2C1_SDA_1|GPIO_SPEED_50MHz)     /* PB7 */

/* SPI1 */
#define GPIO_SPI1_MISO (GPIO_SPI1_MISO_1|GPIO_SPEED_50MHz) /* PA6 - D12 */
#define GPIO_SPI1_MOSI (GPIO_SPI1_MOSI_1|GPIO_SPEED_50MHz) /* PB5 - */
#define GPIO_SPI1_SCK  (GPIO_SPI1_SCK_1|GPIO_SPEED_50MHz)  /* PA5 - D13*/

/****************************************************************************
 * Public Data
 ****************************************************************************/

#ifndef __ASSEMBLY__

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */