#include "CommandInterpreter.h"

#define HELP1 "?"
#define HELP2 "help"

#define QUIT1 "quit"
#define QUIT2 "exit"
#define QUIT3 "q"

#define ADD_PROFILE "add profile "

#define ADD_DATABASE "add database "

#define LOAD_LIST "load list"
#define LOAD_PROFILE "load profile "
#define LOAD_DATABASE "load database "
#define RELOAD "reload"

#define PRINT "print"

#define STATE "state"

CommandInterpreter::CommandInterpreter(DataHandler *dhi)
{
  dh = dhi;
  error_message.clear();
}

bool CommandInterpreter::handle(std::string &command)
{
  bool error = true;
  error_message.clear();

  /* attempt to handle command */

  // before everything.
  try {

  //=======================//
  // QUIT                  //
  //=======================//
  
  if ((command == QUIT1) ||
      (command == QUIT2) ||
      (command == QUIT3))
  {
    error = !dh->closeFiles();
    exit(0);
  }

  //=======================//
  // HELP                  //
  //=======================//

  else if ((command == HELP1) ||
           (command == HELP2))
  {
    error = false;

    printf("Commands:\n");
    printf("   Help - prints this dialog:\n");
    printf("     %s, %s\n", HELP1, HELP2);
    printf("   Quit - exits program:\n");
    printf("     %s, %s, %s\n", QUIT1, QUIT2, QUIT3);
    printf("   Add Profile - Add entry to profile list.\n");
    printf("     %s <name>\n", ADD_PROFILE);
    printf("   Add Database - Add entry to selected profiles db list.\n");
    printf("     %s <name>\n", ADD_DATABASE);
    printf("   Load List - Load the list of profiles.\n");
    printf("     %s \n", LOAD_LIST);
    printf("   Load Profile - Load chosen profile.\n");
    printf("     %s <name>\n", LOAD_PROFILE);
    printf("   Load Database - Load chosen database using profile.\n");
    printf("     %s <name>\n", LOAD_DATABASE);
    printf("   Reload - Reloads the current opened file.\n");
    printf("     %s\n", RELOAD);
    printf("   Print - prints list of profiles.\n");
    printf("     %s\n", PRINT);
    printf("   State - prints out current state info.\n");
    printf("     %s\n", STATE);
  }

  //=======================//
  // STATE                 //
  //=======================//
  else if (command == STATE)
  {
    error = false;

    printf("Profile name = %s\n", dh->getProfile().c_str());
    printf("Database name = %s\n", dh->getDatabase().c_str());

    printf("Opened File = %s, type = %d\n",
        dh->getOpenedFilename().c_str(), dh->getOpenedType());
    
  }

  //=======================//
  // ADD PROFILE <string>  //
  //=======================//
  // If the command begins with add_profile.
  else if (0 == command.find(ADD_PROFILE))
  {
    // TODO: Check if it already exists.
    error = !dh->addProfile( &command[ strlen(ADD_PROFILE) ] );
    dh->reloadFile();
  }

  else if (0 == command.find(ADD_DATABASE))
  {
    char *cP = &command[strlen(ADD_DATABASE)];

    if (!isdigit( cP[0] ))
    {
      error = true;
      error_message = "bad type, use form \"add database <TYPE> <NAME>\"";
    }
    // TODO: don't use arrow anti-pattern
    else
    {
      if (isdigit( cP[0] ))
      {
        int type = cP[0];
      }
      if (isdigit( cP[1] ))
        int type = (type * 10) + cP[1];

      // TODO: Check type is valid.

      error = !dh->addDatabase( &command[ strlen(ADD_DATABASE) ] );
      dh->reloadFile();
    }
  }

  //=======================//
  // LOAD PROFILE LIST     //
  //=======================//
  else if (0 == command.find(LOAD_LIST))
  {
    dh->loadProfiles();
    error = false;
  }

  //=======================//
  // LOAD PROFILE <string> //
  //=======================//
  else if (0 == command.find(LOAD_PROFILE))
  {
    std::string str = &command[ strlen(LOAD_PROFILE) ];
    str += ".dat";
    error = !dh->loadProfile( str );
  }

  //========================//
  // LOAD DATABASE <string> //
  //========================//
  else if (0 == command.find(LOAD_DATABASE))
  {
    error = true;
    error_message = "load database not implemented.";
  }

  //========================//
  // RELOAD                 //
  //========================//
  else if (0 == command.find(RELOAD))
  {
    dh->reloadFile();
  }

  // Prints currently saved results.
  else if (command == PRINT)
  {
    dh->print();
    error = false;
  }

  } catch (StringException &st) {
    printf("in exception");
    error_message = st.what();
  }
  // If end is reached, error is true and error string is empty
  // leave a generic message.
  if (error && (error_message.length() == 0))
  {
    error_message = "Unable to process command <" + command + ">\n";
  }

  // Success is inverse of error.
  return !error;     
}

std::string& CommandInterpreter::getError()
{
  return error_message;
}
