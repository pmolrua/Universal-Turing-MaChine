#ifndef _LOCALIZER_H
#define _LOCALIZER_H

#include "state_machine.h"
#include "tape.h"

void* ini (Tape* tape);
void* loc_0 (Tape* tape);
void* loc_1_A (Tape* tape);
void* loc_1_B (Tape* tape);
void* loc_2 (Tape* tape);
void* loc_3 (Tape* tape);
void* halt (Tape* tape);

#endif