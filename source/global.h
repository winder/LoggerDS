#ifndef GLOBAL_H
#define GLOBAL_H


// Setup the data handler depending on platform.
#ifdef CLI
#include "PCDataHandler.h"
typedef Singleton<PCDataHandler> DataHandlerSingleton;
#elif NDS
#include "NDSDataHandler.h"
typedef Singleton<NDSDataHandler> DataHandlerSingleton;
#endif

#endif
