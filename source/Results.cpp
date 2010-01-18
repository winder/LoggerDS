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

bool Results::addNode( char* text, int type )
{
  if (type == TEXT)
  {
    addNode( new Node(text) );
  }
}

Node* Results::getNode(int index)
{
  int count;
  std::list<Node*>::iterator it;
  for (it=data.begin(), count=0; (count < index) && (it!=data.end()); it++)
    delete (*it);
    printf("%s,", (*it)->getString().c_str());
  return NULL;
}

void Results::print()
{
  std::list<Node*>::iterator it;
  for (it=data.begin(); it!=data.end(); it++)
  {
    if (it != data.begin())
      printf(",");
    printf("%s", (*it)->getString().c_str());
  }
  printf("\n");
  fflush(stdout);
}

void Results::clear()
{
  // data is a list of pointers, so delete them before clearing them out.
  std::list<Node*>::iterator it;
  for (it=data.begin(); it!=data.end(); it++)
    delete (*it);

  data.clear();
}

