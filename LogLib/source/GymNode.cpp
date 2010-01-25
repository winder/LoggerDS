#include "GymNode.h"

// Expected format:
//                    field: | date  | type  | minutes | miles/pounds |
//            variable type: | <int> | <int> |  <int>  |     <int>    |
bool GymNode::validate()
{
  std::string tmp;
  size_t start = 0;

  size_t end = string_value.find(' ');
  if (end == std::string::npos)
    return false;

  // get time.
  tmp = string_value.substr(start, end);
  timestamp = atoi(tmp.c_str());

  // 0 is a valid type.
  if (type == 0)
    return false;

  start = end + 1;
  end = string_value.find(' ', end + 1 );
  tmp = string_value.substr(start, end - start);
  type = atoi( tmp.c_str() );

  if ((type == 0) && (string_value[0] != '0'))
    return false;

  start = end + 1;
  end = string_value.find(' ', end + 1 );
  tmp = string_value.substr(start, end - start);
  minutes = atoi( tmp.c_str() );

  if (minutes == 0)
    return false;

  start = end + 1;
  end = string_value.find(' ', end + 1 );
  // this should be the last value, so it will return npos.
  if (end != std::string::npos)
    return false;
  tmp = string_value.substr(start);
  miles = atoi( tmp.c_str() );

  if (miles == 0)
    return false;

  return true;
}

time_t GymNode::getDate()
{
  return timestamp;
}

int GymNode::getType()
{
  return type;
}

int GymNode::getMinutes()
{
  return minutes;
}

int GymNode::getMiles()
{
  return miles;
}

int GymNode::getPounds()
{
  return pounds;
}

