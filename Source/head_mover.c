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

#include "head_mover.h"

state_function hea_0_A (Tape* tape)
{
	char readed;

	if (move_left_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'M':
			write_tape(tape, 'A');
			return (state_function) hea_1;
		default:
			write_tape(tape, readed);
			return (state_function) hea_0_A;
	}
}


state_function hea_0_B (Tape* tape)
{
	char readed;

	if (move_left_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'M':
			write_tape(tape, 'B');
			return (state_function) hea_1;
		default:
			write_tape(tape, readed);
			return (state_function) hea_0_B;
	}
}


state_function hea_1	(Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'X':
			write_tape(tape, 'X');
			return (state_function) hea_2;
		case 'A':
			write_tape(tape, '0');
			return (state_function) hea_1;
		case 'B':
			write_tape(tape, '1');
			return (state_function) hea_1;
		default:
			write_tape(tape, readed);
			return (state_function) hea_1;
	}
}


state_function hea_2	(Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case '0':
			write_tape(tape, '0');
			return (state_function) hea_3;
		case '1':
			write_tape(tape, '1');
			return (state_function) hea_3;
		default:
			write_tape(tape, readed);
			return (state_function) hea_2;
	}
}


state_function hea_3	(Tape* tape)
{
	char readed;

	if (move_left_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case '0':
			write_tape(tape, 'S');
			return (state_function) hea_4_0;
		case '1':
			write_tape(tape, 'S');
			return (state_function) hea_4_1;
		case 'A':
			write_tape(tape, '0');
			return (state_function) hea_3;
		case 'B':
			write_tape(tape, '1');
			return (state_function) hea_3;		
		default:
			write_tape(tape, readed);
			return (state_function) hea_3;
	}
}


state_function hea_4_0 (Tape* tape)
{
	char readed;

	if (move_left_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'A':
			write_tape(tape, '0');
			return (state_function) hea_5_A;
		case 'B':
			write_tape(tape, '0');
			return (state_function) hea_5_B;
		default:
			write_tape(tape, readed);
			return (state_function) hea_4_0;
	}
}


state_function hea_4_1 (Tape* tape)
{
	char readed;

	if (move_left_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'A':
			write_tape(tape, '1');
			return (state_function) hea_5_A;
		case 'B':
			write_tape(tape, '1');
			return (state_function) hea_5_B;
		default:
			write_tape(tape, readed);
			return (state_function) hea_4_1;
	}
}


state_function hea_5_B (Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case '0':
			write_tape(tape, 'M');
			return (state_function) hea_6_0;
		case '1':
			write_tape(tape, 'M');
			return (state_function) hea_6_1;
		default:
			write_tape(tape, readed);
			return (state_function) hea_5_B;
	}
}



state_function hea_5_A (Tape* tape)
{
	char readed;

	if (move_left_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case '0':
			write_tape(tape, 'M');
			return (state_function) hea_6_0;
		case '1':
			write_tape(tape, 'M');
			return (state_function) hea_6_1;
		default:
			write_tape(tape, readed);
			return (state_function) hea_5_A;
	}
}


state_function hea_6_0 (Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'S':
			write_tape(tape, 'A');
			return (state_function) ini;
		default:
			write_tape(tape, readed);
			return (state_function) hea_6_0;
	}
}


state_function hea_6_1 (Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'S':
			write_tape(tape, 'B');
			return (state_function) ini;
		default:
			write_tape(tape, readed);
			return (state_function) hea_6_1;
	}
}

