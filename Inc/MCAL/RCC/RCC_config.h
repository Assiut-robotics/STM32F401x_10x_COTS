/*
 * RCC_config.h
 *
 *  Created on:	Jul 26, 2022
 *  Author:		Ali Emad Ali
 *
 *  References:
 *  	STM RM0368:	6.	Reset and clock control (RCC) for STM32F401xB/C and STM32F401xD/E
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*	values of external clocks (if used)	*/
#define RCC_HSE_CLK		25000000
#define RCC_LSE_CLK		8000000
/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~		*/

/*	enable switches of clock sources	*/
#define RCC_HSI_EN		true
#define RCC_HSE_EN		false
#define RCC_PLL_EN		false
#define RCC_CSS_EN		false
/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~		*/

/**
 * the clock source to use as system clock source
 * remember:
 * typedef enum{
 *	 RCC_SYSCLOCKSWITCH_HSI = 0,
 *	 RCC_SYSCLOCKSWITCH_HSE = 1,
 *	 RCC_SYSCLOCKSWITCH_PLL = 2,
 * }RCC_SYSCLOCKSWITCH;
 */
#define RCC_SYS_SOURCE	RCC_SYSCLOCKSWITCH_HSI
/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~		*/

/*	HSE pybass (if used)	*/
#if RCC_HSE_EN
#define RCC_HSE_BYPASSED	false
#endif	/*	RCC_HSE_EN	*/
/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~		*/

/**
 * PLL configuration (if used)
 * remember:
 *  typedef enum{
 *	 RCC_PLLSOURCE_HSI = 0,
 *	 RCC_PLLSOURCE_HSE = 1
 * }RCC_PLLSOURCE;
 * and:
 *  typedef enum{
 *   RCC_PLLDEVISIONFACTOR_2 = 0,
 *   RCC_PLLDEVISIONFACTOR_4 = 1,
 *   RCC_PLLDEVISIONFACTOR_6 = 2,
 *   RCC_PLLDEVISIONFACTOR_8 = 3,
 * }RCC_PLLSYSDEVISIONFACTOR;
 */
#if RCC_PLL_EN
#define RCC_PLL_CLK_SOURCE	RCC_PLLSOURCE_HSI

// user does not have to calculate 3 parameters of PLL, just give
// a wanted frequency and compiler will do the rest.
//#define RCC_PLL_PREPROSSESED_CALULATION		false

/*#if RCC_PLL_PREPROSSESED_CALULATION
#define RCC_F_SYS		40000000

#else*/
#define RCC_PLL_MULTIPLICATION_FACTOR	211
#define RCC_PLL_SYS_DIVISION_FACTOR		RCC_PLLDEVISIONFACTOR_6
#define RCC_PLL_MAIN_DIVISION_FACTOR	8

//#endif /* RCC_PLL_PREPROSSESED_CALULATION */
#endif /* RCC_PLL_EN */
/*	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~		*/



#endif /* RCC_CONFIG_H_ */