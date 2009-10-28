#ifndef GLOBAL_H
#define GLOBAL_H


// Setup the data handler depending on platform.
#ifdef CLI
  #include "PCDataHandler.h"
  #define DATAHANDLER PCDataHandler
  //#define Singleton<PCDataHandler> DataHandlerSingleton;
#elif NDS
  #include "NDSDataHandler.h"
  #define DATAHANDLER NDSDataHandler
  //typedef Singleton<NDSDataHandler> DataHandlerSingleton;
#endif

#endif
