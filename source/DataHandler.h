#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#define MAX_LINE_IN_FILE 256

//#include "Singleton.h"
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
    virtual ~DataHandler();

    // Accessor
    void print();

    void setProfile(std::string& p);
    void setDatabase(std::string& db);

    const std::string& getProfile();
    const std::string& getDatabase();

    /* Filesystem Commands */
    // create
    bool createProfile(std::string& p);
    bool createDatabase(std::string& db);

    // load file
    // load all profiles from profiles.dat to Results.
    bool loadProfiles();
    bool loadProfile(const std::string& pf);
//    virtual bool loadDatabase(std::string& db) = 0;

    // read
    bool readProfiles();

    // write
    bool addProfile(const std::string& profileName);
    bool addDatabase(const std::string& databaseName);
    bool writeLineToFile(const std::string&, FILE*, unsigned int);
    bool writeToDatabase(const std::string& lineInDatabase);

    // close files
    bool closeFiles();

  protected:
    virtual FILE* openFile(const char* filename, const char* permissions) = 0;

    FILE *pProfiles;
    FILE *pProfile;
    FILE *pDatabase;
    Results *res;

    std::string profile;
    std::string database;
};

// global definition.
//typedef Singleton<DataHandler> DataHandlerSingleton;
#endif
