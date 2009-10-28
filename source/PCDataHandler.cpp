#include "PCDataHandler.h"

PCDataHandler::PCDataHandler():DataHandler()
{};

PCDataHandler::~PCDataHandler(){};

// load all profiles to Results.
bool PCDataHandler::loadProfiles()
{
  // Locate profiles.dat
  // look in current directory only.
  pProfile = fopen("profiles.dat", "r+");

  if (pProfile == NULL)
  {
    pProfile = fopen("profiles.dat", "w+");
    fputs("Default\n", pProfile);
    fputs("Owen\n", pProfile);
  }

  readProfile();

  return true;
}

