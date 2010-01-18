#ifndef RESULTS_H
#define RESULTS_H

#include "global.h"
#include <list>
#include "Node.h"
#include <stdio.h>

// This is a simple container class for NODE values.
// It is used to store the content of "database" and will be required to do
// sorts and allow sequential access.

// It should essentially be a wrapper class for the <vector> class...
class Results
{
  public:
    // Information
    unsigned int size();

    bool addNode(Node* n);
    bool addNode(char* text, int type);
    Node* getNode(int index);

    void print();

    void clear();

  private:
    std::list<Node*> data;
};

#endif
