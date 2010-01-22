#include "ConsoleKeyboardState.h"

void ConsoleKeyboardState::init()
{
  consoleDemoInit();
  keyboardDemoInit();
  keyboardShow();
}

void ConsoleKeyboardState::updateState(const touchPosition &touch)
{
  int key = keyboardUpdate();
  if (key > 0)
    iprintf("%c", key);
}
