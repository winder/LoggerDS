#include "NDSDataHandler.h"

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
