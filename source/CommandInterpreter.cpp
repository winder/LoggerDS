#include "CommandInterpreter.h"

#define help1 "?"
#define help2 "help"

#define quit1 "quit"
#define quit2 "exit"
#define quit3 "q"

#define add_profile "add profile "

#define add_database "add database "

#define load_profile "load profile "
#define load_database "load database "

#define print_profile "print profile"

#define print "print"

#define state "state"

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
  try{

  //=======================//
  // QUIT                  //
  //=======================//
  
  if ((command == quit1) ||
      (command == quit2) ||
      (command == quit3))
  {
    error = !dh->closeFiles();
    exit(0);
  }

  //=======================//
  // HELP                  //
  //=======================//

  else if ((command == help1) ||
           (command == help2))
  {
    error = false;

    printf("Commands:\n");
    printf("   Help - prints this dialog:\n");
    printf("     %s, %s\n", help1, help2);
    printf("   Quit - exits program:\n");
    printf("     %s, %s, %s\n", quit1, quit2, quit3);
    printf("   Add Profile - Add entry to profile list.\n");
    printf("     %s <name>\n", add_profile);
    printf("   Add Database - Add entry to selected profiles db list.\n");
    printf("     %s <name>\n", add_database);
    printf("   Load Profile - Load chosen profile.\n");
    printf("     %s <name>\n", load_profile);
    printf("   Load Database - Load chosen database using profile.\n");
    printf("     %s <name>\n", load_database);
    printf("   Print Profile - prints selected profile list.\n");
    printf("     %s\n", print_profile);
    printf("   Print - prints list of profiles.\n");
    printf("     %s\n", print);
    printf("   State - prints out current state info.\n");
    printf("     %s\n", state);
  }

  //=======================//
  // STATE                 //
  //=======================//
  else if (command == state)
  {
    error = false;

    printf("Profile name = %s\n", dh->getProfile().c_str());
    printf("Database name = %s\n", dh->getDatabase().c_str());
    
  }

  //=======================//
  // ADD PROFILE <string>  //
  //=======================//
  // If the command begins with add_profile.
  else if (0 == command.find(add_profile))
  {
    // TODO: Check if it already exists.
    error = !dh->addProfile( &command[ strlen(add_profile) ] );
  }

  else if (0 == command.find(add_database))
  {
    char *cP = &command[strlen(add_database)];

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

      error = !dh->addDatabase( &command[ strlen(add_database) ] );
    }
  }

  //=======================//
  // LOAD PROFILE <string> //
  //=======================//
  else if (0 == command.find(load_profile))
  {
    std::string str = &command[ strlen(load_profile) ];
    str += ".dat";
    error = !dh->loadProfile( str );
  }
  else if (0 == command.find(load_database))
  {
    error = true;
    error_message = "load database not implemented.";
  }

  // Prints currently saved results.
  else if (command == print)
  {
    error = !dh->readProfiles();
  }

  //========================//
  // PRINT PROFILE <string> //
  //========================//
  else if (command == print_profile)
  {
    //???
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
