#include "localizer.h"

void* ini (Tape* tape)
{
	char readed;

	if (move_left_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case '0':
			write_tape(tape, 'A');
			return (void *) ini;
		case '1':
			write_tape(tape, 'B');
			return (void *) ini;
		case 'Y':
			write_tape(tape, 'Y');
			return (void *) loc_0;
		default:
			write_tape(tape, readed);
			return (void *) ini;
	}
}


void* loc_0 (Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'A':
			write_tape(tape, '1');
			return (void *) loc_1_A;
		case 'B':
			write_tape(tape, '2');
			return (void *) loc_1_B;
		case 'X':
			write_tape(tape, 'X');
			return (void *) cop_0;
		default:
			write_tape(tape, readed);
			return (void *) loc_0;
	}
}


void* loc_1_A (Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case '0':
			write_tape(tape, 'A');
			return (void *) loc_2;
		case '1':
			write_tape(tape, 'B');
			return (void *) loc_3;
		default:
			write_tape(tape, readed);
			return (void *) loc_1_A;
	}
}


void* loc_1_B (Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case '0':
			write_tape(tape, 'A');
			return (void *) loc_3;
		case '1':
			write_tape(tape, 'B');
			return (void *) loc_2;
		default:
			write_tape(tape, readed);
			return (void *) loc_1_B;
	}
}


void* loc_2 (Tape* tape)
{
	char readed;

	if (move_left_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'Y':
			write_tape(tape, 'Y');
			return (void *) loc_0;
		default:
			write_tape(tape, readed);
			return (void *) loc_2;
	}
}



void* loc_3 (Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'X':
			write_tape(tape, 'X');
			return (void *) ini;
		case 'Y':
			write_tape(tape, 'Y');
			return (void *) halt;
		default:
			write_tape(tape, readed);
			return (void *) loc_2;
	}
}

void* halt (Tape *tape)
{
	end_tape(tape);
	exit(0);
}