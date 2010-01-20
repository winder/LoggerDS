#ifndef GASNODE_H
#define GASNODE_H

#include <string>
#include <time.h>
#include <stdlib.h>
#include "Node.h"

class GasNode: public Node
{
  public:

    virtual bool validate();

    time_t getDate();
    double getGallons();
    int getMiles();
    double pricePerGallon();
    double totalPrice();

  protected:
    time_t timestamp;
    double gallons;
    double price;
    int miles;
    
};

#endif
