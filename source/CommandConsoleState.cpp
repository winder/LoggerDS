#ifdef NDS

#include "CommandConsoleState.h"

void CommandConsoleState::init()
{
	consoleDemoInit();  //setup the sub screen for printing

//	keyboardDemoInit();

//	keyboardShow();
}

void CommandConsoleState::updateState()
{
//  int key = keyboardUpdate();
//  if (key > 0) iprintf("%c", key);
  printf("'");
}

#endif
