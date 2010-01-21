#ifndef PLATFORM_H
#define PLATFORM_H


// Setup the data handler depending on platform.
#ifdef CLI
  #include "pc/PCDataHandler.h"
  #define DATAHANDLER PCDataHandler
#elif NDS
  #include "NDSDataHandler.h"
  #define DATAHANDLER NDSDataHandler
#endif

#endif
