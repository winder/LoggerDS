#ifndef NDSDATAHANDLER_H
#define NDSDATAHANDLER_H

#ifdef NDS
#include <fat.h>
#endif

#include "DataHandler.h"

#include <vector>
#include <stdio.h>
#include <string.h>

class NDSDataHandler: public DataHandler
{
  public:
    NDSDataHandler();
    virtual ~NDSDataHandler();

  protected:
    FILE* openFile(const char*, const char*);
};

#endif
