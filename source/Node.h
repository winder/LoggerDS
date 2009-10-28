#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
  public:
    // Constructor and Constructor + initialization.
    Node();
    Node(const char* input);
    Node(std::string& input);

    // Get the string representation of the node.
    const std::string& getString();
    void setString(const char* input);
    void setString(std::string& input);

  private:
    std::string string_value;
};

#endif
