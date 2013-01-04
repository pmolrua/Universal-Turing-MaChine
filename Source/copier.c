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

#include "copier.h"

state_function cop_0	(Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case '0':
			write_tape(tape, 'A');
			return (state_function) cop_1_A;
		case '1':
			write_tape(tape, 'B');
			return (state_function) cop_1_B;
		default:
			write_tape(tape, readed);
			return (state_function) cop_0;
	}
}

state_function cop_1_A (Tape* tape)
{
	char readed;

	if (move_left_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'Y':
			write_tape(tape, 'Y');
			return (state_function) cop_2_A;
		default:
			write_tape(tape, readed);
			return (state_function) cop_1_A;
	}
}

state_function cop_1_B (Tape* tape)
{
	char readed;

	if (move_left_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'Y':
			write_tape(tape, 'Y');
			return (state_function) cop_2_B;
		default:
			write_tape(tape, readed);
			return (state_function) cop_1_B;
	}
}

state_function cop_2_A (Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'X':
			write_tape(tape, 'X');
			return (state_function) hea_0_A;
		case '0':
		case '1':
			write_tape(tape, 'A');
			return (state_function) cop_3;
		default:
			write_tape(tape, readed);
			return (state_function) cop_2_A;
	}
}

state_function cop_2_B (Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'X':
			write_tape(tape, 'X');
			return (state_function) hea_0_B;
		case '0':
		case '1':
			write_tape(tape, 'B');
			return (state_function) cop_3;
		default:
			write_tape(tape, readed);
			return (state_function) cop_2_B;
	}
}

state_function cop_3 (Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'X':
			write_tape(tape, 'X');
			return (state_function) cop_0;
		default:
			write_tape(tape, readed);
			return (state_function) cop_3;
	}
}