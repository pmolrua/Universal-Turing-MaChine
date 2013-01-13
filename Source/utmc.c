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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tape.h"
#include "state_machine.h"
#include "io.h"

int main(int argc, char const *argv[])
{
	ARGUMENTS* arg;
	p_state_function func = ini;
	Tape* tape;

	/* Checking the input arguments */
	arg = ini_arguments(argc, argv);

	if (arg == NULL)
		exit(1);

	if (arg->help == 1)
	{
		printf("~~~~~~~HELP: This is a Universal Turing MaChine, coded by Pablo Molins.\n");
		printf("~~~~~~~HELP: It's distributed under a GNU General Public License.\n");
		printf("~~~~~~~HELP: Usage: ./utmc [options]\n");
		printf("~~~~~~~HELP: Options:\n");
		printf("~~~~~~~HELP:\t-i <input_file>\tIf not file is specified, default name is 'ini.utmc'\n");
		printf("~~~~~~~HELP:\t-o <output_file>\tIf not file is specified, default name is 'end.utmc'\n");
		printf("~~~~~~~HELP:\t-d\tDebbug mode\n");
		printf("~~~~~~~HELP:\t-h, --help\tThis help it's shown.\n");
		end_arguments(arg);
		exit(0);
	}


	/* The MaChine starts */
	tape = new_tape();

	if (tape == NULL)
	{
		fprintf(stderr, "~~~~~~~ERROR: Something went wrong... new_tape() didn't work.\n");
		exit(1);
	}

	ini_tape(tape, "10000000000000MY00X00000X01110Y");

	if (arg->debug == 1)
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

	end_arguments(arg);
	end_tape(tape);

	return 0;
}
