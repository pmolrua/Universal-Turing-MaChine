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

Tape* new_tape()
{
	Tape* tape;

	tape = (Tape *) malloc(sizeof(tape[0]));

	if (tape == NULL)
		return NULL;

	tape->start = NULL;
	tape->head = NULL;
	tape->end = NULL;

	return tape;
}

status ini_tape(Tape* tape, char* values)
{
	int i, len = strlen(values);

	assert(tape != NULL);
	assert(values != NULL);

	tape->start = (char *) malloc(len);

	if (tape->start == NULL)
		return ERR;

	memcpy(tape->start, values, len);

	tape->end = tape->start + len;

	for (i = 0; i < len && tape->start[i] != 'M'; i++);

	if (i == len && tape->start[i] != 'M')
	{
		free(tape->start);
		fprintf(stderr, "ERROR: No 'M' in the tape.\n");
		return ERR;
	}

	tape->head = tape->start + i;

	return OK;
}

void write_tape(Tape* tape, char value)
{
	assert(tape != NULL);
	assert(tape->head != NULL);

	*(tape->head) = value;

	return;
}

char read_tape(Tape* tape)
{
	assert(tape != NULL);
	assert(tape->head != NULL);

	return *(tape->head);
}

status move_right_tape(Tape* tape)
{
	assert(tape != NULL);
	assert(tape->start != NULL);
	assert(tape->head != NULL);
	assert(tape->end != NULL);

	if (tape->head == tape->end)
	{
		char* temp;
		int tam = tape->end - tape->start + 1;
		int i;

		temp = (char *) malloc(tam * sizeof(temp[0]));

		if (temp == NULL)
			return ERR;

		temp[tam - 1] = '0';

		for (i = 0; i < tam; i++)
			temp[i] = tape->start[i];

		free(tape->start);

		tape->start = temp;
		tape->end = temp + tam;
		tape->head = temp + tam - 1;
	}

	tape->head++;

	return OK;
}

status move_left_tape(Tape* tape)
{
	assert(tape != NULL);
	assert(tape->start != NULL);
	assert(tape->head != NULL);
	assert(tape->end != NULL);

	if (tape->head == tape->start)
	{
		char* temp;
		int tam = tape->end - tape->start + 1;
		int i;

		temp = (char *) malloc(tam * sizeof(temp[0]));

		if (temp == NULL)
			return ERR;

		temp[0] = '0';

		for (i = 1; i < tam; i++)
			temp[i] = tape->start[i - 1];

		free(tape->start);

		tape->start = temp;
		tape->end = temp + tam;
		tape->head = temp + 1;
	}

	tape->head--;

	return OK;
}

void print_tape(Tape* tape)
{
	printf("____________________________________________\n");

	printf("To be implemented\n");

	printf("____________________________________________\n");

	return;
}


void end_tape(Tape* tape)
{
	free(tape->start);
	free(tape);

	return;
}

void exit_tape_error(Tape* tape)
{
	fprintf(stderr, "FATAL ERROR: Not enough memory for the tape.\n");

	end_tape(tape);

	exit(1);
}