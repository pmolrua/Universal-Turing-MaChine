/**************************************************************

	Universal Turing MaChine
	Copyright (C) 2013  Pablo Molins - pablo.molins@gmail.com

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

state_function hea_0_A (Tape* tape);
state_function hea_0_B (Tape* tape);
state_function hea_1	(Tape* tape);
state_function hea_2	(Tape* tape);
state_function hea_3	(Tape* tape);
state_function hea_4_0 (Tape* tape);
state_function hea_4_1 (Tape* tape);
state_function hea_5_A (Tape* tape);
state_function hea_5_B (Tape* tape);
state_function hea_6_0 (Tape* tape);
state_function hea_6_1 (Tape* tape);

#endif