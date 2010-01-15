#ifndef STATE_H
#define STATE_H

#include <stdio.h>
/* state interface.
 * will be used to facilitate menu transitions,
 */

class state
{
  public:
    virtual void init() = 0;
    virtual void updateState() = 0;
    int changeState(){ return transition; }

  protected:
    int transition;
};

#endif
