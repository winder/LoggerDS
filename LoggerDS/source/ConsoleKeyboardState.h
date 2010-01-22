#ifndef CONSOLEKEYBOARDSTATE_H
#define CONSOLEKEYBOARDSTATE_H

#include <nds.h>
#include <stdio.h>

#include "state.h"

class ConsoleKeyboardState: public state
{
  public:
    virtual void init();
    virtual void updateState(const touchPosition &touch);

  private:
    
};

#endif
