#ifndef CP1610_H
#define CP1610_H
/*
	This file is part of FreeIntv.

	FreeIntv is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	FreeIntv is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with FreeIntv.  If not, see http://www.gnu.org/licenses/
*/

#include <stdint.h>
typedef struct CP1610_Context_t
{
	uint32_t Version;
	int (*OpCodes[0x400])(int);
	int Interuptable[0x400];
	const char *Nmemonic[0x400];

	unsigned int R[8]; // Registers R0-R7

	int InstructionRegister; // four external lines?

	int Flag_DoubleByteData;
	int Flag_InteruptEnable;
	int Flag_Carry;
	int Flag_Sign;
	int Flag_Zero;
	int Flag_Overflow;
	
	unsigned int Memory[0x10000];
} CP1610_Context, *PCP1610_Context;

extern CP1610_Context gCP1610_Context;
#define CTX(x) gCP1610_Context.x
#define CP1610_SERIALIZE_VERSION 1

void CP1610Init(void); // Adds opcodes to lookup tables

void CP1610Reset(void); // reset cpu

int CP1610Tick(int debug); // execute a single instruction, return cycles used

#endif
