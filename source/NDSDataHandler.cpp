#include "NDSDataHandler.h"

NDSDataHandler::NDSDataHandler():DataHandler()
{};

NDSDataHandler::~NDSDataHandler()
{};

// load all profiles to Results.
FILE* NDSDataHandler::openFile(const char* filename, const char* permissions)
{
  // TODO: search the proper path
  return fopen(filename, permissions);
}

/*
// load all profiles to Results.
bool NDSDataHandler::loadProfiles()
{
  // Locate profiles.loggerDS
  // search for LoggerDS directory
  // if not found, create
  // if create, add profile for DS owner?

  if (pProfile != NULL)
    fclose (pProfile);

  return true;
}
*/
