#ifdef NDS
#include "DS.h"
#endif

#include "global.h"
#include <stdio.h>
#include <string>
#include "CommandInterpreter.h"


int main(void)
{
  // This is the only place the DATAHANDLER macro is used.
  DataHandler* dh = new DATAHANDLER();
  dh->loadProfiles();

  CommandInterpreter *ci = new CommandInterpreter(dh);
  std::string s_command;
  char command[512];

  #ifdef NDS
  InitializeConsole();
  InitializeFilesystem();
  InitializeGraphics();
  #endif

	bool running = true;
	while(running)
	{


    #ifdef CLI
		  printf(">");
      fflush(stdout);

      char *newline;
      // Get input, strip off newline character.
      if ( fgets(command, sizeof(command), stdin) != NULL )
      {
        newline = strchr(command, '\n');
        if (newline != NULL)
          *newline = '\0';
      }
    #elif NDS
      printf("> DSMODE, command = asdfg\n");
      strcpy(command, "asdfg");
      // GUI Interaction
      // This block happens once per frame
    #endif

    s_command = command;

    // if command has a value, handle it.
    if (0 != s_command.length())
    {
      if (ci->handle(s_command))
      { /* nothing for good case. */ }
      else
      {
        #ifdef CLI
          printf("Command Failed: %s", ci->getError().c_str());
        #elif NDS
          printf("Command Failed: %s", ci->getError().c_str());
        #endif
      }
    }

    #ifdef NDS
      swiWaitForVBlank();
    #endif

	}

	return 0;
}
