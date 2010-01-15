#ifndef DSINIT_H
#define DSINIT_H

#ifdef NDS

#include <nds.h>
#include <fat.h>

#include "CommandConsoleState.h"

#ifdef __cplusplus
extern "C" {
#endif

void InitializeConsole();

void InitializeFilesystem();

void InitializeGraphics();

#ifdef __cplusplus
};
#endif

// ifdef NDS
#endif

// define DSINIT_H
#endif
