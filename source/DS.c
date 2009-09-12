#include "DS.h"

#ifdef NDS

void InitializeConsole()
{
  defaultExceptionHandler();
  consoleDemoInit();
}

void InitializeFilesystem()
{
  fatInitDefault();
/* // file write test.  file isn't written until fclose is called.
  // init lib fat
  if (fatInitDefault())
  {
    printf("lib fat init success.\n");
    FILE *fp;
    fp = fopen("/results.dat", "w");
    if (fp)
    {
      printf("opened file /results.dat\n");
      for (int i=0; i<=10; ++i)
        fprintf(fp, "%d, %d\n", i, i*i);
      printf("wrote to file.\n");
      fclose(fp);
      printf("closed the file.\n");
    }
    else
      printf("failed to open file.");
    while(true){};
  }
  else 
  {
    printf("lib fat init failure.");
    while(true){};
  }
*/
}

void InitializeGraphics()
{

}

#endif

