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

#ifndef _LOCALIZER_H
#define _LOCALIZER_H

#include "state_machine.h"
#include "tape.h"

void* ini (Tape* tape);
void* loc_0 (Tape* tape);
void* loc_1_A (Tape* tape);
void* loc_1_B (Tape* tape);
void* loc_2 (Tape* tape);
void* loc_3 (Tape* tape);
void* halt (Tape* tape);

#endif