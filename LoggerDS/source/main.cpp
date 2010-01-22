#include <fat.h>
#include <nds.h>

#include <loglib/global.h>
#include <loglib/CommandInterpreter.h>
#include <loglib/NDSDataHandler.h>

#include <stdio.h>
#include <string>

#include "ConsoleKeyboardState.h"

int main(void)
{
  // This is the only place the DATAHANDLER macro is used.
  DataHandler* dh = new NDSDataHandler();

  CommandInterpreter *ci = new CommandInterpreter(dh);
  std::string s_command;
  char command[512];

  int i=0;
  defaultExceptionHandler();
  consoleDemoInit();
  if (fatInitDefault())
    printf("lib fat init success.\n");
  else
    printf("lib fat failed.\n");

  touchPosition touch;

  ConsoleKeyboardState cks;
  cks.init();

  // Real main loop
  while (1)
  {
    touchRead(&touch);
    cks.updateState(touch);
    
    swiWaitForVBlank();
  }

	bool running = true;
	while(running)
	{
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
      default:
        s_command = "q";
        break;
    }
    printf("Command: '%s'\n", s_command.c_str());

    // GUI Interaction
    // This block happens once per frame

    // if command has a value, handle it.
    if (0 != s_command.length())
    {
      if (ci->handle(s_command))
      {
        // nothing for good case.
      }
      else
      {
        printf("Command Failed: %s", ci->getError().c_str());
      }
    }

    swiWaitForVBlank();

	}

	return 0;
}
