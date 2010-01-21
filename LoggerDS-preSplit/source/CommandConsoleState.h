#ifdef NDS

#ifndef COMMANDCONSOLESTATE_H
#define COMMANDCONSOLESTATE_H

#include <nds.h>
#include <stdio.h>
#include "state.h"

class CommandConsoleState: public state
{
  public:
    virtual void init();
    virtual void updateState();

  private:

};

#endif

#endif
