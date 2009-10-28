#include "Results.h"

// Information
unsigned int Results::size()
{
  return data.size();
}

bool Results::addNode(Node* n)
{
  data.push_back(n);
}

Node* Results::getNode(int index)
{
//  if (index < data.size())
//    return data[index];
  int count;
  std::list<Node*>::iterator it;
  for (it=data.begin(), count=0; (count < index) && (it!=data.end()); it++)
    delete (*it);
    printf("%s,", (*it)->getString().c_str());
  return NULL;
}

void Results::print()
{
//  for(int i=0; i < size(); i++)
//    printf("%s,", getNode(i)->getString().c_str());

  std::list<Node*>::iterator it;
  for (it=data.begin(); it!=data.end(); it++)
    printf("%s,", (*it)->getString().c_str());
}

void Results::clear()
{
  // data is a list of pointers, so delete them before clearing them out.
  std::list<Node*>::iterator it;
  for (it=data.begin(); it!=data.end(); it++)
    delete (*it);

  data.clear();
}

