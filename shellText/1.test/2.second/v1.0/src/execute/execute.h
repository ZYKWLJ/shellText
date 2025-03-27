#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// #include "../0.testGuideNewUser/CoreHelp.h"
#include "../instructionsLists/instructionList.h"
#include "../commonTools/color/color.h"
#include "../commonTools/eliminateSpace/eliminateSpace.h"
int isValidInstruction(char *str);
void executeInstruction(int Instruction_index);
void execute(char *str);
#endif