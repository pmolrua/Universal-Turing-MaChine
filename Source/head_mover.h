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

#ifndef _HEAD_MOVER_H
#define _HEAD_MOVER_H

#include "state_machine.h"
#include "tape.h"

void* hea_0_A (Tape* tape);
void* hea_0_B (Tape* tape);
void* hea_1	(Tape* tape);
void* hea_2	(Tape* tape);
void* hea_3	(Tape* tape);
void* hea_4_0 (Tape* tape);
void* hea_4_1 (Tape* tape);
void* hea_5_0 (Tape* tape);
void* hea_5_1 (Tape* tape);
void* hea_6_A (Tape* tape);
void* hea_6_B (Tape* tape);

#endif