/*
 * NVIC_private.h
 *
 *  Created on:	Aug 6, 2022
 *  Author:		Ali Emad Ali
 *	
 *	Resources:
 *		*
 *
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#include "Target_config.h"

#if TARGET_ID == STM32F401x
/*typedef struct{
	u32 ISER[8];
	u32 reserved1[0x18];
	u32 ICER[8];
	u32 reserved2[0x18];
	u32 ISPR[8];
	u32 reserved3[0x18];
	u32 ICPR[8];
	u32 reserved4[0x18];
	u32 IABR[8];
	u32 reserved5[0x38];
	u8 IPR[240];
	u32 reserved6[0x284];
	u32 STIR;
}NVIC_t;*/

#define NVIC ((volatile NVIC_t*)0xE000E100)

#elif TARGET_ID == STM32F10x
typedef struct{
	u32 ISER[3];
	u32 reserved1[0x1C];
	u32 ICER[3];
	u32 reserved2[0x1D];
	u32 ISPR[3];
	u32 reserved3[0x1D];
	u32 ICPR[3];
	u32 reserved4[0x1D];
	u32 IABR[3];
	u8 reserved5[0xF7];
	u8 IPR[81];
	u8 reserved6[0xAAB];
	u32 STIR;
}NVIC_t;

#define NVIC ((volatile NVIC_t*)0xE000E100)

#endif

#endif /* NVIC_PRIVATE_H_ */
