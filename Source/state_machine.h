/**************************************************************

	Universal Turing MaChine
	Copyright (C) 2013  Pablo Molins

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program. If not, see <http://www.gnu.org/licenses/>.

**************************************************************/

#ifndef _STATE_MACHINE_H
#define _STATE_MACHINE_H

#include "tape.h"

typedef void* (* state_function) (Tape*);
	
typedef enum {O = '0', I = '1', X = 'X', Y = 'Y', A = 'A', B = 'B', M = 'M', S = 'S', MAX_INPUTS} inputs;

typedef enum {
	INI, 
	LOC_0, 
	LOC_1_A, 
	LOC_1_B, 
	LOC_2, 
	LOC_3, 
	COP_0, 
	COP_1_A, 
	COP_1_B, 
	COP_2_A, 
	COP_2_B, 
	COP_3, 
	HEA_0_A,
	HEA_0_B,
	HEA_1,
	HEA_2,
	HEA_3,
	HEA_4_0,
	HEA_4_1,
	HEA_5_0,
	HEA_5_1,
	HEA_6_A,
	HEA_6_B,
	MAX_STATES
} states;

#include "localizer.h"
#include "copier.h"
#include "head_mover.h"

#endif