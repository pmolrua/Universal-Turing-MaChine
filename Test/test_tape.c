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


#include "../Source/tape.h"

int main(int argc, char const *argv[])
{
	Tape* tape;

	tape = new_tape();

	if (tape == NULL)
		return 1;

	ini_tape(tape, "1234567890M");

	move_right_tape(tape);

	write_tape(tape, 'A');

	move_right_tape(tape);

	write_tape(tape, 'B');

	move_right_tape(tape);

	print_tape(tape, 0);

	printf("\n");

	end_tape(tape);

	tape = new_tape();

	if (tape == NULL)
		return 1;

	ini_tape(tape, "M1234567890");

	move_left_tape(tape);

	write_tape(tape, 'A');

	move_left_tape(tape);

	write_tape(tape, 'B');

	move_left_tape(tape);

	print_tape(tape, 0);

	tape = new_tape();

	if (tape == NULL)
		return 1;

	ini_tape(tape, "M");

	move_left_tape(tape);
	move_left_tape(tape);
	move_left_tape(tape);
	move_left_tape(tape);
	move_left_tape(tape);
	move_left_tape(tape);
	move_left_tape(tape);
	move_left_tape(tape);
	move_left_tape(tape);
	move_left_tape(tape);
	move_left_tape(tape);
	move_left_tape(tape);
	move_left_tape(tape);

	print_tape(tape, 0);

	end_tape(tape);

	tape = new_tape();

	if (tape == NULL)
		return 1;

	ini_tape(tape, "M");

	move_right_tape(tape);
	move_right_tape(tape);
	move_right_tape(tape);
	move_right_tape(tape);
	move_right_tape(tape);
	move_right_tape(tape);
	move_right_tape(tape);
	move_right_tape(tape);
	move_right_tape(tape);
	move_right_tape(tape);
	move_right_tape(tape);
	move_right_tape(tape);
	move_right_tape(tape);

	print_tape(tape, 0);

	end_tape(tape);

	return 0;
}