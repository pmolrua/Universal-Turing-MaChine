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

#ifndef _TAPE_H_
#define _TAPE_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef enum {OK, ERR} status;

typedef struct 
{
	char* start;
	char* head;
	char* end;
}Tape;

Tape* new_tape();

status ini_tape(Tape* tape, char* values);

void write_tape(Tape* tape, char value);

char read_tape(Tape* tape);

status move_right_tape(Tape* tape);

status move_left_tape(Tape* tape);

void print_tape(Tape* tape);

void end_tape(Tape* tape);

void exit_tape_error(Tape* tape);

#endif