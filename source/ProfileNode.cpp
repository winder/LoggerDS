#include "ProfileNode.h"

// Expected format:
//                    field:    | type  | database name |
//            variable type:    | <int> |    <text>     |
bool ProfileNode::validate()
{
  std::string tmp;
  size_t start = 0;

  size_t end = string_value.find(' ');
  if (end == std::string::npos)
    return false;

  // get type.
  tmp = string_value.substr(start, end);
  type = atoi(tmp.c_str());

  if ((type == 0) && (string_value[0] != '0'))
    return false;

  start = end + 1;
  end = string_value.find(' ', end + 1 );
  // this should be the last value, so it should return npos.
  if (end != std::string::npos)
    return false;
  name = string_value.substr(start);

  return true;
}

const std::string& ProfileNode::getDatabase()
{
  return name;
}

int ProfileNode::getType()
{
  return type;
}
