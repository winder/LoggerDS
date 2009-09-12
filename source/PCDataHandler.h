#ifndef PCDATAHANDLER_H
#define PCDATAHANDLER_H

#include "Singleton.h"
#include "DataHandler.h"

#include <vector>
#include <stdio.h>
#include <string.h>

class PCDataHandler: public DataHandler
{
  public:
    PCDataHandler():DataHandler(){};

    virtual ~PCDataHandler(){};
    /* Filesystem Commands */

    // create
//    bool createProfile(char* profile);
//    bool createDatabase(char* dbName);

    // load
    bool loadProfiles(); // load all profiles to Results.
//    bool loadProfile(char* profile);
//    bool loadDatabase(char* dbName);

    // Loads filesystem for "profile_*"
    bool loadDatabases(std::string& p);

  private:
};

#endif
