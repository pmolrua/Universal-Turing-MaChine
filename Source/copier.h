#ifndef _COPIER_H
#define _COPIER_H

#include "state_machine.h"
#include "tape.h"

void* cop_0	(Tape* tape);
void* cop_1_A (Tape* tape);
void* cop_1_B (Tape* tape);
void* cop_2_A (Tape* tape);
void* cop_2_B (Tape* tape);
void* cop_3 (Tape* tape);

#endif