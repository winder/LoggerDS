#ifndef COMMANDINTERPRETER_H
#define COMMANDINTERPRETER_H

#include "global.h"
#include "StringException.h"

#include <stdio.h>
#include <string>
#include <stdlib.h>


class CommandInterpreter
{
  public:
    CommandInterpreter();

    // Handle a command.
    bool handle(std::string&);
    std::string& getError(){ return error_message; }

  private:
    std::string error_message;
};

#endif
