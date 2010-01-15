#include "DataHandler.h"

DataHandler::DataHandler()
{
  profile.clear();
  database.clear();
  pProfiles = NULL;
  pProfile = NULL;
  pDatabase = NULL;

  res = new Results();
}

DataHandler::~DataHandler()
{
  closeFiles();
}

void DataHandler::print()
{
  res->print();
}

void DataHandler::setProfile(std::string& p)
{
  profile = p;
}

void DataHandler::setDatabase(std::string& db)
{
  database = db;
}

const std::string& DataHandler::getProfile()
{
  return profile;
}

const std::string& DataHandler::getDatabase()
{
  return database;
}

bool DataHandler::createProfile(std::string& profile)
{ return true; }

bool DataHandler::createDatabase(std::string& dbName)
{ return true; }

bool DataHandler::readProfiles()
{
  if (pProfiles == NULL)
    throw StringException("Bad file pointer.");

  rewind(pProfiles);

  if ( feof(pProfiles) )
    throw StringException("End of file.");

  res->clear();

  char read[256];
  char *newline;
  // Read the file.
  while (fgets(read, sizeof(read), pProfiles))
  {
    newline = strchr(read, '\n');
    if (newline != NULL)
      *newline = '\0';
    res->addNode( new Node(read) ); 
  }

  res->print();

  return true;
}

bool DataHandler::writeToDatabase(const std::string& lineInDatabase)
{
  return writeLineToFile(lineInDatabase, pDatabase, MAX_LINE_IN_FILE);
}

bool DataHandler::addProfile(const std::string& profileName)
{
  return writeLineToFile(profileName, pProfiles, MAX_LINE_IN_FILE);
}

bool DataHandler::addDatabase(const std::string& databaseName)
{
  return writeLineToFile(databaseName, pProfile, MAX_LINE_IN_FILE);
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
  if (pProfiles != NULL)
  {
    fclose(pProfiles);
    printf("closed profiles...\n");
  }
  if (pProfile != NULL)
  {
    fclose(pProfile);
    printf("closed \"%s\"...\n", profile.c_str());
  }
  if (pDatabase != NULL)
  {
    fclose(pDatabase);
    printf("closed database...\n");
  }

  return true;
}

// load all profiles.dat to Results.
bool DataHandler::loadProfiles()
{
  // Locate profiles.dat
  // look in current directory only.
  pProfiles = openFile("profiles.dat", "r+");

  if (pProfiles == NULL)
  {
    pProfiles = openFile("profiles.dat", "w+");
    fputs("Default\n", pProfiles);
    fputs("Owen\n", pProfiles);
  }

  readProfiles();

  return true;
}

// load specified profile.
bool DataHandler::loadProfile(const std::string& pf)
{
  if (pProfile != NULL)
    fclose(pProfile);

  profile = pf;
  pProfile = openFile(pf.c_str(), "r+");

  if (pProfile == NULL)
  {
    pProfile = openFile(pf.c_str(), "w+");
  }

  if (pProfile == NULL)
    throw StringException("Couldn't open the file for some reason...");
    

//  readFile();

  return true;
}
