#ifndef PROFILENODE_H
#define PROFILENODE_H

#include <string>
#include <stdlib.h>
#include "Node.h"

class ProfileNode: public Node
{
  public:
    virtual bool validate();
    const std::string& getDatabase();
    int getType();

  protected:
    std::string name;
    int type;
};

#endif
