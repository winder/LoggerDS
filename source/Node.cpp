#include "Node.h"

Node::Node()
{};

Node::Node(const char* input)
{
  string_value = input;
}

Node::Node(std::string& input)
{
  string_value = input;
}

// Get the string representation of the node.
const std::string& Node::getString()
{
  return string_value;
}

void Node::setString(const char* input)
{
  string_value = input;
}

void Node::setString(std::string& input)
{
  string_value = input;
}
