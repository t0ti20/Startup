/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  Author:  Khaled El-Sayed (@t0ti20)
 *  Created:  05.02.2023
 *  File:  Startup.c
 *  Module:  Global
 *  Description:  Startup in C File For ARM Cortex-M3
******************************************************************/
#include <stdint.h>		/*Include Standerd Types*/
#define _STACK_SIZE_	0x3E8
/******************************************************************/
/******************************************************************/
extern unsigned int _START_LMA_DATA_;
extern unsigned int _START_VMA_DATA_;
extern unsigned int _END_VMA_DATA_;
extern unsigned int _START_BSS_;
extern unsigned int _END_BSS_;
/******************************************************************/
/******************************************************************/
extern void Intery_Function();
void _RESET_(void);
void NMI_Handler(void)__attribute__((weak,alias("_RESET_")));
void Hard_Fault_Handler(void)__attribute__((weak,alias("_RESET_")));
/******************************************************************/
/******************************************************************/
void(* const _VECTORS_[])(void)__attribute__((section(".vectors")))=
{
	(void(*)())((&_END_BSS_)+_STACK_SIZE_),
	&_RESET_,
	&NMI_Handler,
	&Hard_Fault_Handler,
};
/******************************************************************/
/******************************************************************/
void _RESET_(void)
{
	unsigned int SECTION_SIZE;
	unsigned char *SOURCE_POINTER,*DISTINATION_POINTER;
	/*-----------------------------------------*/
	/*   Copy Data Section From Flash To Ram   */
	/*-----------------------------------------*/
	SECTION_SIZE=(unsigned char*)&_END_VMA_DATA_-(unsigned char*)&_START_VMA_DATA_;
	SOURCE_POINTER=((unsigned char*)(&_START_LMA_DATA_));
	DISTINATION_POINTER=((unsigned char*)(&_START_VMA_DATA_));
	while(SECTION_SIZE--)
	{
		*((unsigned char *)DISTINATION_POINTER++)=*((unsigned char *)SOURCE_POINTER++);
	}
	/*-----------------------------------------*/
	/*      Initialize BSS Section In RAM      */
	/*-----------------------------------------*/
	SECTION_SIZE=(unsigned char*)&_END_BSS_-(unsigned char*)&_START_BSS_;
	DISTINATION_POINTER=((unsigned char*)(&_START_BSS_));
	while(SECTION_SIZE--)
	{
		*((unsigned char *)DISTINATION_POINTER++)=(unsigned char)(0xFF);
	}
	/*-----------------------------------------*/
	/*      	Jump To Main Program	       */
	/*-----------------------------------------*/
	while(1)
	{
		Intery_Function();
	}
}
/******************************************************************/
/******************************************************************/
