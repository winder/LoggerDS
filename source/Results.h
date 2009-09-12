#ifndef RESULTS_H
#define RESULTS_H

#include <vector>
#include "Node.h"

// This is a simple container class for NODE values.
// It is used to store the content of "database" and will be required to do
// sorts and allow sequential access.

// It should essentially be a wrapper class for the <vector> class...
class Results
{
  public:

    // Information
    unsigned int size(){ return data.size(); }

    bool addNode(Node* n);
    Node* getNode(int index);

    void print();

    void clear()
    {
      // data is a vector of pointers, so delete them before clearing them out.
      std::vector<Node*>::iterator it;
      for (it=data.begin(); it!=data.end(); it++)
        delete (*it);

      data.clear();
    }

  private:
    std::vector<Node*> data;

};

#endif
