#ifdef NDS
#include "DS.h"
#endif

#include "global.h"
#include "platform.h"
#include <stdio.h>
#include <string>
#include "CommandInterpreter.h"

int main(void)
{
  // This is the only place the DATAHANDLER macro is used.
  DataHandler* dh = new DATAHANDLER();
//  dh->loadProfiles();

  CommandInterpreter *ci = new CommandInterpreter(dh);
  std::string s_command;
  char command[512];

  #ifdef NDS
  int i=0;
  InitializeConsole();
  InitializeFilesystem();
  InitializeGraphics();
  /*
    // Create an entirely seperate main loop for DS / PC eventually.
    CommandConsoleState ccs;
    ccs.init();

    while(1)
    {
      ccs.updateState();
      swiWaitForVBlank();
    }
  */
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
//      command[0] = rand() % 78;
//      printf("> DSMODE, command = %s\n", command);
//      strcpy(command, command);
      switch (i++)
      {
        case 0:
          s_command = "load list";
          break;
        case 1:
          s_command = "add profile Owen";
          break;
        case 2:
          s_command = "add profile Another";
          break;
        case 3:
          s_command = "add profile Another";
          break;
        case 4:
          s_command = "load profile Owen";
          break;
        case 5:
          s_command = "add database 0 first";
          break;
        case 6:
          s_command = "add database 1 second";
          break;
        case 7:
          s_command = "add database 2 third";
          break;
        case 8:
          s_command = "add database 2 third";
          break;
        case 9:
          s_command = "load database first";
          break;
        case 10:
          s_command = "q";
          break;
      }
      printf("Command: '%s'\n", s_command.c_str());

      // GUI Interaction
      // This block happens once per frame
    #endif

    #ifndef NDS
    s_command = command;
    #endif

    // if command has a value, handle it.
    if (0 != s_command.length())
    {
      if (ci->handle(s_command))
      {
        // nothing for good case.
      }
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
