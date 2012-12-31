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