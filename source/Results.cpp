#include "Results.h"

bool Results::addNode(Node* n)
{
  data.push_back(n);
}

Node* Results::getNode(int index)
{
  if (index < data.size())
    return data[index];
  return NULL;
}

void Results::print()
{
  for(int i=0; i < size(); i++)
    printf("%s,", getNode(i)->getString().c_str());
}
