#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// #include "../0.testGuideNewUser/CoreHelp.h"
#include "InstructionList/InstructionList.h"
#include "../0.color/color.h"
#include "EliminateSpace/EliminateSpace.h"
int isValidInstruction(char *str);
void executeInstruction(int Instruction_index);
void execute(char *str);
#endif