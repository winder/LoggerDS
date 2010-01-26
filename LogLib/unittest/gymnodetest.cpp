#include "GymNode.h"
#include "Node.h"
#include <stdio.h>
#include <string>
#include <time.h>
using namespace std;

int main()
{
  GymNode *n = new GymNode();

  printf("Format = <date> <type> <minutes> <miles>\n");

  string str;

  printf("TESTS:\n");
  str = "1234 1234 1234 1234";
  printf("\t'%s' (expect yes): %s\n", str.c_str(), n->setString(str) ? "yes" : "no");
  printf("date = %d, type = %d, ,minutes = %d miles = %d\n",
            (int)n->getDate(), n->getType(), n->getMinutes(), n->getMiles());

  str = "1 1 1 1";
  printf("\t'%s' (expect yes): %s\n", str.c_str(), n->setString(str) ? "yes" : "no");
  printf("date = %d, type = %d, ,minutes = %d miles = %d\n",
            (int)n->getDate(), n->getType(), n->getMinutes(), n->getMiles());

  str = "1234567 454346346  1.25 4";
  printf("\t'%s' (expect no): %s\n", str.c_str(), n->setString(str) ? "yes" : "no");
  printf("date = %d, type = %d, ,minutes = %d miles = %d\n",
            (int)n->getDate(), n->getType(), n->getMinutes(), n->getMiles());

  str = "-5 -5 -5 -5";
  printf("\t'%s' (expect yes): %s\n", str.c_str(), n->setString(str) ? "yes" : "no");
  printf("date = %d, type = %d, ,minutes = %d miles = %d\n",
            (int)n->getDate(), n->getType(), n->getMinutes(), n->getMiles());

  return 0;
}
