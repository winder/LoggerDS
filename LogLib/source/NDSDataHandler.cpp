#include "NDSDataHandler.h"

NDSDataHandler::NDSDataHandler():DataHandler()
{};

NDSDataHandler::~NDSDataHandler()
{};

// load all profiles to Results.
FILE* NDSDataHandler::openFile(const char* filename, const char* permissions)
{
  std::string sur = "/data/LoggerDS/";
  sur += filename;
  // TODO: search the proper path
  FILE* fp = fopen(sur.c_str(), permissions);
  if (fp == NULL)
  {
    printf("failed to open '%s'\n", sur.c_str());
    fp = fopen( filename, permissions );
    if (fp == NULL)
    {
      printf("failed to open '%s'\n", filename);
    }
  }
  return fp;
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
