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

	tape->end = tape->start + len - 1;

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

status realloc_tape_right(Tape* tape)
{
	assert(tape != NULL);
	assert(tape->start != NULL);
	assert(tape->head != NULL);
	assert(tape->end != NULL);

	char* temp;
	int len = tape->end - tape->start + 2; /* 1 for the actual length, and another for the new */

	temp = (char *) malloc(len * sizeof(temp[0]));

	if (temp == NULL)
		return ERR;

	memcpy(temp, tape->start, (len - 1) * sizeof(temp[0]));

	free(tape->start);

	tape->start = temp;
	tape->end = temp + (len - 1);
	tape->head = tape->end;

	*tape->head = '0';

	return OK;
} 

status move_right_tape(Tape* tape)
{
	assert(tape != NULL);
	assert(tape->start != NULL);
	assert(tape->head != NULL);
	assert(tape->end != NULL);

	if (tape->head == tape->end)
		return realloc_tape_right(tape);

	tape->head++;

	return OK;
}


status realloc_tape_left(Tape* tape)
{
	assert(tape != NULL);
	assert(tape->start != NULL);
	assert(tape->head != NULL);
	assert(tape->end != NULL);

	char* temp;
	int len = tape->end - tape->start + 2; /* 1 for the actual length, and another for the new */

	temp = (char *) malloc(len * sizeof(temp[0]));

	if (temp == NULL)
		return ERR;

	memcpy(temp + 1, tape->start, (len - 1) * sizeof(temp[0]));

	free(tape->start);

	tape->start = temp;
	tape->end = temp + (len - 1);
	tape->head = tape->start;

	*tape->head = '0';

	return OK;
}

status move_left_tape(Tape* tape)
{
	assert(tape != NULL);
	assert(tape->start != NULL);
	assert(tape->head != NULL);
	assert(tape->end != NULL);

	if (tape->head == tape->start)
		return realloc_tape_left(tape);

	tape->head--;

	return OK;
}


void print_tape(Tape* tape, unsigned int len)
{
	char* temp;

	printf("____________________________________________\n");

	printf("|");

	for (temp = tape->start; temp <= tape->end; temp++)
		printf("%c|", *temp);

	printf("\n");

	printf("--------------------------------------------\n");

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