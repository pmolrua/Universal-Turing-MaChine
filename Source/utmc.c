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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tape.h"
#include "state_machine.h"

int main(int argc, char const *argv[])
{
	int i;
	int help = 0, debug = 0;
	p_state_function func = ini;
	Tape* tape;

	/* Checking the input arguments */
	for (i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-d") == 0)
			debug = 1;
		else
		{
			fprintf(stderr, "~~~~~~~ERROR: %s it's not a valid argument\n", argv[i]);
			help = 1;
		}
	}

	if (help == 1)
	{
		fprintf(stderr, "~~~~~~~HELP: This is a Universal Turing MaChine, coded by Pablo Molins.\n");
		fprintf(stderr, "~~~~~~~HELP: More information soon.\n");
		exit(0);
	}

	tape = new_tape();

	if (tape == NULL)
	{
		fprintf(stderr, "~~~~~~~ERROR: Something went wrong... new_tape() didn`t work\n");
		exit(1);
	}

	ini_tape(tape, "10000000000000MY00X00000X01110Y");

	if (debug == 1)
	{
		while (func != NULL)
		{
			func = (p_state_function) func(tape);
			print_tape(tape, 0);
		}
	}
	else
	{
		while (func != NULL)
		{
			func = (p_state_function) func(tape);
		}
	}

	end_tape(tape);

	return 0;
}