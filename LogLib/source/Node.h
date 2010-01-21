#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
  public:
    // Constructor and Constructor + initialization.
    Node();
// No additional constructors so input can be validated.
//    Node(const char* input);
//    Node(std::string& input);

    // Get the string representation of the node.
    const std::string& getString();
    bool setString(const char* input);
    bool setString(const std::string& input);
    virtual bool validate();

  protected:
    std::string string_value;
};

#endif
