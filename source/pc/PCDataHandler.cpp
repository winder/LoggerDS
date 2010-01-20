#include "PCDataHandler.h"

PCDataHandler::PCDataHandler():DataHandler()
{};

PCDataHandler::~PCDataHandler(){};

// load all profiles to Results.
FILE* PCDataHandler::openFile(const char* filename, const char* permissions)
{
  return fopen(filename, permissions);
}

