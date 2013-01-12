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

#ifndef _IO_H
#define _IO_H

	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <assert.h>

	typedef struct 
	{
		int help;
		int debug;
		char* input_file;
		char* output_file;
	}ARGUMENTS;

	ARGUMENTS* ini_arguments(int argc, char const *argv[]);
	void end_arguments(ARGUMENTS* arg);

#endif