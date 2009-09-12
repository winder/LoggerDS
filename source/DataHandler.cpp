#include "DataHandler.h"

DataHandler::DataHandler()
{
  profile.clear();
  database.clear();
  pProfile = NULL;
  pDatabase = NULL;

  res = new Results();
}

bool DataHandler::createProfile(std::string& profile)
{ return true; }
bool DataHandler::createDatabase(std::string& dbName)
{ return true; }

bool DataHandler::readProfile()
{
  if (pProfile == NULL)
    throw StringException("Bad file pointer.");

  rewind(pProfile);

  if ( feof(pProfile) )
    throw StringException("End of file.");

  res->clear();

  char read[256];
  char *newline;
  // Read the file.
  while (fgets(read, sizeof(read), pProfile))
  {
    newline = strchr(read, '\n');
    if (newline != NULL)
      *newline = '\0';
    res->addNode( new Node(read) ); 
  }

  res->print();

  return true;
}

bool DataHandler::loadDatabase(std::string& dbName)
{ return true; }

bool DataHandler::writeToDatabase(const std::string& lineInDatabase)
{
  return writeLineToFile(lineInDatabase, pDatabase, MAX_LINE_IN_FILE);
}

bool DataHandler::writeNewProfile(const std::string& profileName)
{
  return writeLineToFile(profileName, pProfile, MAX_LINE_IN_FILE);
}

bool DataHandler::writeLineToFile(const std::string& line, FILE* file, unsigned int maxLine)
{
  if (file == NULL)
  {
    throw StringException("Error: trying to write to NULL file.\n");
    return false;
  }
  else if (line.length() > maxLine)
  {
    throw StringException("Error: Line too long.\n");
    return false;
  }

  fseek(file, 0, SEEK_END);
  printf("Writing <%s> to file...", line.c_str());
  fprintf(file, "%s\n", line.c_str()); //puts(line, file);
  //fputs("\n", file);
  fflush(file);
  return true;
}

bool DataHandler::closeFiles()
{
  if (pProfile != NULL)
  {
    fclose(pProfile);
    printf("closed profile...\n");
  }
  if (pDatabase != NULL)
  {
    fclose(pDatabase);
    printf("closed database...\n");
  }

  return true;
}
