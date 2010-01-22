#ifndef STATE_H
#define STATE_H

#include <stdio.h>

// need this for touchPosition
#include <nds.h>
/* state interface.
 * will be used to facilitate menu transitions,
 */

class state
{
  public:
    virtual void init() = 0;
    virtual void updateState(const touchPosition &touch) = 0;
    int changeState(){ return transition; }

  protected:
    int transition;
};

#endif
