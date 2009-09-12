#ifndef NDSDATAHANDLER_H
#define NDSDATAHANDLER_H

#ifdef NDS
#include <fat.h>
#endif

#include "Singleton.h"
#include "DataHandler.h"

#include <vector>
#include <stdio.h>
#include <string.h>

class NDSDataHandler: public DataHandler
{
  public:
    NDSDataHandler():DataHandler(){};
    virtual ~NDSDataHandler(){};

    /* Filesystem Commands */

    // create
//    bool createProfile(char* profile);
//    bool createDatabase(char* dbName);

    // load
    bool loadProfiles(); // load all profiles to Results.
//    bool loadProfile(char* profile);
//    bool loadDatabase(char* dbName);

  private:
};

#endif
