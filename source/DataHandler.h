#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#define MAX_LINE_IN_FILE 256

#include "Singleton.h"
#include "Results.h"
#include "StringException.h"

#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>

class DataHandler
{
  public:
    DataHandler();

    // Destructor checks if files are open and closes them.
    // For some reason this is never getting called on the PC
    virtual ~DataHandler()
    { closeFiles(); };

    /* Filesystem Commands */
    // create
    virtual bool createProfile(std::string& profile);
    virtual bool createDatabase(std::string& dbName);

    // load file
    virtual bool loadProfiles() = 0; // load all profiles to Results.
    virtual bool loadDatabase(std::string& dbName);

    // read
    virtual bool readProfile();

    // write
    bool writeLineToFile(const std::string&, FILE*, unsigned int);
    bool writeNewProfile(const std::string& profileName);
    bool writeToDatabase(const std::string& lineInDatabase);

    // close files
    bool closeFiles();

    // Getters
    const std::string& getProfileName(){ return profile; }
    const std::string& getDatabaseName(){ return database; }

  protected:
    FILE *pProfile;
    FILE *pDatabase;

  private:
    std::string profile;
    std::string database;
    Results *res;

};

// global definition.
//typedef Singleton<DataHandler> DataHandlerSingleton;
#endif
