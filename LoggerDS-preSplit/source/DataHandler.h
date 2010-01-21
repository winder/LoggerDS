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

    const std::string& getProfile();
    const std::string& getDatabase();

    const std::string& getOpenedFilename();
    const int getOpenedType();

    /* Filesystem Commands */
    // create
    bool createProfile(std::string& p);
    bool createDatabase(std::string& db);

    // load file
    // load all profiles from profiles.dat to Results.
    bool loadProfiles();
    bool loadProfile(const std::string& pf);
    bool loadDatabase(std::string& db);

    // read
    bool readFile(const std::string& filename, FILE *fp, int type);
    bool reloadFile();

    // write
    bool addProfile(const std::string& profileName);
    bool addDatabase(const std::string& databaseString);
    bool writeLineToFile(const std::string&, FILE*, unsigned int);
    bool writeToDatabase(const std::string& lineInDatabase);

    // close files
    bool closeFiles();

  protected:
    virtual FILE* openFile(const char* filename, const char* permissions) = 0;

    std::string currentFilename;
    FILE *currentFile;
    int currentType;

    FILE *pProfiles;
    FILE *pProfile;
    FILE *pDatabase;
    Results *res;

    std::string profile;
    std::string database;
};

#endif
