#ifndef STATE_H
#define STATE_H

#include <stdio.h>
#include <nds.h>
#include "global.h"

/* state interface.
 * will be used to facilitate menu transitions,
 */

class state
{
  public:
    // All initialization functions needed when changing to this state.
    virtual void init() = 0;

    // Update state, called once per frame.
    virtual void updateState(const touchPosition &touch) = 0;

    // Returns the state's ID 
    virtual int stateId() = 0;

    // Returns -1 for no change or the state which should be changed to.
    int changeState(){ return transition; }

  protected:
    int transition;
};

#endif
