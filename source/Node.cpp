#include "Node.h"

Node::Node()
{};
/*
Node::Node(const char* input)
{
  string_value = input;
}

Node::Node(std::string& input)
{
  string_value = input;
}
*/

// Get the string representation of the node.
const std::string& Node::getString()
{
  return string_value;
}

bool Node::setString(const char* input)
{
  string_value = input;
  return validate();
}

bool Node::setString(std::string& input)
{
  string_value = input;
  return validate();
}

// Base class takes a string, no validation on what it contains.
bool Node::validate()
{
  return true;
}
