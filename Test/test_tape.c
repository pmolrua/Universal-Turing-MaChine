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


#include "tape.h"

int main(int argc, char const *argv[])
{
	int i;
	
	Tape* tape;

	tape = new_tape();

	if (tape == NULL)
		return 1;

	ini_tape(tape, "1234567890M");

	move_right_tape(tape);

	move_right_tape(tape);

	write_tape(tape, 'J');

	move_right_tape(tape);

	for (i = 1; i < 21; i++)
	{
		printf("%c|", read_tape(tape));

		if (i % 10 == 0)
			printf("\n");

		move_left_tape(tape);
	}

	printf("\n");

	return 0;
}