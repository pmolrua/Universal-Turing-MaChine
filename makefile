

	# Universal Turing MaChine
	# Copyright (C) 2013  Pablo Molins - pablo.molins@gmail.com

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
SOURCE = ./Source/
TEST = ./Test/
BUILD = ./Build/



utmc.app: $(BUILD)utmc.o $(BUILD)tape.o $(BUILD)localizer.o $(BUILD)copier.o $(BUILD)head_mover.o $(BUILD)io.o
	@echo "#---------------------------"
	@echo "# Building $@"
	$(CC) $(CFLAGS) -o $@ $(BUILD)utmc.o $(BUILD)tape.o $(BUILD)localizer.o $(BUILD)copier.o $(BUILD)head_mover.o $(BUILD)io.o

$(BUILD)utmc.o: $(SOURCE)utmc.c
	@echo "#---------------------------"
	$(CC) $(CFLAGS) -c -o $@ $(SOURCE)utmc.c 

$(BUILD)tape.o: $(SOURCE)tape.c
	@echo "#---------------------------"
	$(CC) $(CFLAGS) -c -o $@ $(SOURCE)tape.c 

$(BUILD)localizer.o: $(SOURCE)localizer.c
	@echo "#---------------------------"
	@echo "# Compiling $@"
	$(CC) $(CFLAGS) -c -o $@ $(SOURCE)localizer.c 

$(BUILD)copier.o: $(SOURCE)copier.c
	@echo "#---------------------------"
	@echo "# Compiling $@"
	$(CC) $(CFLAGS) -c -o $@ $(SOURCE)copier.c

$(BUILD)head_mover.o: $(SOURCE)head_mover.c
	@echo "#---------------------------"
	@echo "# Compiling $@"
	$(CC) $(CFLAGS) -c -o $@ $(SOURCE)head_mover.c 

$(BUILD)io.o: $(SOURCE)io.c
	@echo "#---------------------------"
	@echo "# Compiling $@"
	$(CC) $(CFLAGS) -c -o $@ $(SOURCE)io.c 


# Tests

tests: test_tape.exe

test_tape.app: $(BUILD)tape.o $(BUILD)test_tape.o
	@echo "#---------------------------"
	$(CC) $(CFLAGS) -o $@ $(BUILD)tape.o $(BUILD)test_tape.o

$(BUILD)test_tape.o: $(TEST)test_tape.c
	@echo "#---------------------------"
	$(CC) $(CFLAGS) -c -o $@ $(TEST)test_tape.c 


# The other stuff

config:
	mkdir Build

.PHONY: clean
clean:
	rm -f -r *.o 

