#ifndef GYMNODE_H
#define GYMNODE_H

#include <string>
#include <time.h>
#include <stdlib.h>
#include "Node.h"

enum WorkoutTypes
{
  TREADMILL,
  BIKE,
  WEIGHTS
};

class GymNode: public Node
{
  public:

    // Expected format:
    //                    field: | date  | type  | minutes | miles/pounds |
    //            variable type: | <int> | <int> |  <int>  |     <int>    |
    virtual bool validate();

    time_t getDate();
    int getType();
    int getMinutes();
    int getMiles();
    int getPounds();

  protected:
    time_t timestamp;
    int type;
    int minutes;
    int miles;
    int pounds;
};

#endif
