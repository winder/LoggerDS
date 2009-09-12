#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
  public:
    Node(){};
    Node(const char* input)
    {
      string_value = input;
    }

    Node(std::string& input)
    {
      string_value = input;
    }

    // Get the string representation of the node.
    const std::string& getString(){ return string_value; }

    void setString(const char* input){ string_value = input; } 
  private:
    std::string string_value;
};

#endif
