

	# Universal Turing MaChine
	# Copyright (C) 2013  Pablo Molins

	# This program is free software: you can redistribute it and/or modify
	# it under the terms of the GNU General Public License as published by
	# the Free Software Foundation, either version 3 of the License, or
	# any later version.

	# This program is distributed in the hope that it will be useful,
	# but WITHOUT ANY WARRANTY; without even the implied warranty of
	# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	# GNU General Public License for more details.

	# You should have received a copy of the GNU General Public License
	# along with this program. If not, see <http://www.gnu.org/licenses/>.



CC = gcc -ansi -pedantic
#CFLAGS = -Wall -O3
CFLAGS = -Wall -g
EXE = utmc
SOURCE = ./Source/
TEST = ./Test/
BUILD = ./Build/

test: test_tape.exe

utmc: utmc.o tape.o localizer.o copier.o head_mover.o
	@echo "#---------------------------"
	@echo "# Building $@"
	@echo "# Depends on $^"
	@echo "# Has been modified $<"
	$(CC) $(CFLAGS) -o $@ utmc.o tape.o localizer

.PHONY: clean
clean:
	rm -f -r *.o 

test_tape.exe: $(BUILD)tape.o $(BUILD)test_tape.o
	@echo "#---------------------------"
	$(CC) $(CFLAGS) -o $@ $(BUILD)tape.o $(BUILD)test_tape.o

$(BUILD)tape.o: $(SOURCE)tape.c
	@echo "#---------------------------"
	$(CC) $(CFLAGS) -c -o $@ $(SOURCE)tape.c 

$(BUILD)test_tape.o: $(TEST)test_tape.c
	@echo "#---------------------------"
	$(CC) $(CFLAGS) -c -o $@ $(TEST)test_tape.c 

