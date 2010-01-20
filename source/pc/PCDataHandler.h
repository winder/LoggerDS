#ifndef PCDATAHANDLER_H
#define PCDATAHANDLER_H

#include "../DataHandler.h"

#include <vector>
#include <stdio.h>
#include <string.h>

class PCDataHandler: public DataHandler
{
  public:
    PCDataHandler();

    virtual ~PCDataHandler();

  protected:
    FILE* openFile(const char* filename, const char* permissions);
};

#endif
