#include "GasNode.h"
#include "Node.h"
#include <string>
#include <stdio.h>
#include <time.h>
using namespace std;

int main()
{
  GasNode *n = new GasNode();

  printf("Format = <date> <miles> <gallons> <price");

  string str;

  printf("TESTS:\n");
  str = "1234 1234 1.234 1.234";
  printf("\t'%s' (expect yes): %s\n", str.c_str(), n->setString(str) ? "yes" : "no");
  printf("date = %d, miles = %d, price = %f gallons = %f;; total = %f\n",
            (int)n->getDate(),
            n->getMiles(),
            n->pricePerGallon(),
            n->getGallons(),
            n->totalPrice());

  str = "1 1 1 1";
  printf("\t'%s' (expect yes): %s\n", str.c_str(), n->setString(str) ? "yes" : "no");
  printf("date = %d, miles = %d, price = %f gallons = %f;; total = %f\n",
            (int)n->getDate(),
            n->getMiles(),
            n->pricePerGallon(),
            n->getGallons(),
            n->totalPrice());

  str = "1234567 454346346  1.25 4";
  printf("\t'%s' (expect yes): %s\n", str.c_str(), n->setString(str) ? "yes" : "no");
  printf("date = %d, miles = %d, price = %f gallons = %f;; total = %f\n",
            (int)n->getDate(),
            n->getMiles(),
            n->pricePerGallon(),
            n->getGallons(),
            n->totalPrice());

  str = "-5 -5 -5 -5";
  printf("\t'%s' (expect yes): %s\n", str.c_str(), n->setString(str) ? "yes" : "no");
  printf("date = %d, miles = %d, price = %f gallons = %f;; total = %f\n",
            (int)n->getDate(),
            n->getMiles(),
            n->pricePerGallon(),
            n->getGallons(),
            n->totalPrice());

  return 0;
}
