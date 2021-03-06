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
  bool ret = true;
  Node *n;

  switch (type)
  {
    case TEXT:
      n = new Node();
      if ( (ret = n->setString(text)) )
        addNode( n );
      break;
    case PROFILE:
      n = new ProfileNode();
      if ( (ret = n->setString(text)) )
        addNode( n );
      break;
  }
      
  return ret;
}

Node* Results::getNode(int index)
{
  int count = 0;
  std::list<Node*>::iterator it;
  for (it=data.begin(); (count < index) && (it!=data.end()); it++, count++);

  return (*it);
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

