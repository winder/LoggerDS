#include "CommandInterpreter.h"

#define quit1 "quit"
#define quit2 "exit"
#define quit3 "q"

#define add_profile "add profile "

#define print_profile "print profile"

CommandInterpreter::CommandInterpreter()
{
  error_message.clear();
}

bool CommandInterpreter::handle(std::string &command)
{
  bool error = true;
  error_message.clear();

  /* attempt to handle command */

  // before everything.
  try{

  // Quit...
  if ((command == quit1) ||
      (command == quit2) ||
      (command == quit3))
  {
    error = !DataHandlerSingleton::getInstance()->closeFiles();
    exit(0);
  }

  // If the command begins with add_profile.
  else if ( 0 == command.find(add_profile))
  {
    error = !DataHandlerSingleton::getInstance()->writeNewProfile(&command[strlen(add_profile)]);
  }

  else if (command == print_profile)
  {
    error = !DataHandlerSingleton::getInstance()->readProfile();
  }

  //} catch (StringException &st) {
  } catch (StringException &st) {
    //error_message = st.what();
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
