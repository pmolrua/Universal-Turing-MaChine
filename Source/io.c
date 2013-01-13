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

#include "io.h"

ARGUMENTS* ini_arguments(int argc, char const *argv[])
{
	int i;
	ARGUMENTS* arg = (ARGUMENTS *) malloc (sizeof(arg[0]));

	if (arg == NULL)
		return NULL;

	arg->input_file = NULL;
	arg->output_file = NULL;
	arg->debug = 0;
	arg->help = 0;


	for (i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "-i") == 0)
		{
			arg->input_file = strdup(argv[++i]);

			if (arg->input_file == NULL)
			{
				fprintf(stderr, "~~~~~~~ERROR: Something went wrong... a strdup() didn't work.\n");
				end_arguments(arg);
				return NULL;
			}
		}
		else if (strcmp(argv[i], "-o") == 0)
		{
			arg->output_file = strdup(argv[++i]);

			if (arg->output_file == NULL)
			{
				fprintf(stderr, "~~~~~~~ERROR: Something went wrong... a strdup() didn't work.\n");
				end_arguments(arg);
				return NULL;
			}
		}
		else if (strcmp(argv[i], "-d") == 0)
			arg->debug = 1;
		else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help"))
			arg->help = 1;
		else
		{
			fprintf(stderr, "~~~~~~~ERROR: %s it's not a valid argument\n", argv[i]);
			arg->help = 1;
		}
	}

	if (arg->input_file == NULL)
		arg->input_file = strdup("ini.utmc");
	if (arg->input_file == NULL)
	{
		fprintf(stderr, "~~~~~~~ERROR: Something went wrong... a strdup() didn't work.\n");
		end_arguments(arg);
		return NULL;	
	}

	if (arg->output_file == NULL)
		arg->output_file = strdup("end.utmc");
	if (arg->output_file == NULL)
	{
		fprintf(stderr, "~~~~~~~ERROR: Something went wrong... a strdup() didn't work.\n");
		end_arguments(arg);
		return NULL;	
	}

	return arg;
}

void end_arguments(ARGUMENTS* arg)
{
	free(arg->input_file);
	free(arg->output_file);
	free(arg);
}

/* return value must be freed after the call */
char* read_tape_from_file(ARGUMENTS* arg)
{
	char* tape = NULL;
	char buf[BUFSIZ];
	FILE* f;
	char* temp;

	assert(arg != NULL);
	assert(arg->input_file != NULL);

	f = fopen(arg->input_file, "r");

	if (f == NULL)
		return NULL;

	/* This loop looks for a valid line. No comments or empty lines */
	do
		if (fgets(buf, BUFSIZ, f) == NULL)
			return NULL;
	while(buf[0] == '#' || buf[0] == '\n');

	/*eprintf("IO: Line %s\n", buf);*/

	temp = strtok(buf, "\n\r\t ");

	tape = (char *) malloc(strlen(temp) + 2);

	if (tape == NULL)
		return NULL;

	tape = strcpy(tape, temp);

	/* If the file is a single line one, then we have finish */
	if (strstr(tape, "Y") != NULL)
		return tape;

	strcat(tape, "Y");

	/* Now we look for the header and initial state and then all the states */
	while(fgets(buf, BUFSIZ, f) != NULL)
	{
		if (buf[0] == '#' || buf[0] == '\n')
			continue;

		/*eprintf("IO: Line %s\n", buf);*/

		temp = strtok(buf, "\n\r\t ");

		tape = (char *) realloc(tape, strlen(temp) + strlen(tape) + 2);

		if (tape == NULL)
			return NULL;

		strcat(tape, temp);
		strcat(tape, "X");
	}

	/* We are done, and so we change the last 'X' with the 'Y' */

	tape[strlen(tape) - 1] = 'Y';

	/*eprintf("IO: End tape: %s\n", tape);*/

	fclose(f);

	return tape;
}
