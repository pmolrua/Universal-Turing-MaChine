#include "copier.h"

void* cop_0	(Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case '0':
			write_tape(tape, 'A');
			return (void *) cop_1_A;
		case '1':
			write_tape(tape, 'B');
			return (void *) cop_1_B;
		default:
			write_tape(tape, readed);
			return (void *) cop_0;
	}
}

void* cop_1_A (Tape* tape)
{
	char readed;

	if (move_left_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'Y':
			write_tape(tape, 'Y');
			return (void *) cop_2_A;
		default:
			write_tape(tape, readed);
			return (void *) cop_1_A;
	}
}

void* cop_1_B (Tape* tape)
{
	char readed;

	if (move_left_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'Y':
			write_tape(tape, 'Y');
			return (void *) cop_2_B;
		default:
			write_tape(tape, readed);
			return (void *) cop_1_B;
	}
}

void* cop_2_A (Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'X':
			write_tape(tape, 'X');
			return (void *) hea_0_A;
		case '0':
		case '1':
			write_tape(tape, 'A');
			return (void *) cop_3;
		default:
			write_tape(tape, readed);
			return (void *) cop_2_A;
	}
}

void* cop_2_B (Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'X':
			write_tape(tape, 'X');
			return (void *) hea_0_B;
		case '0':
		case '1':
			write_tape(tape, 'B');
			return (void *) cop_3;
		default:
			write_tape(tape, readed);
			return (void *) cop_2_B;
	}
}

void* cop_3 (Tape* tape)
{
	char readed;

	if (move_right_tape(tape) == ERR)
		exit_tape_error(tape);

	readed = read_tape(tape);

	switch(readed){
		case 'X':
			write_tape(tape, 'X');
			return (void *) cop_0;
		default:
			write_tape(tape, readed);
			return (void *) cop_3;
	}
}