#include "GasNode.h"

// Expected format:
//                    field:    | date  | miles | gallons | price   |
//            variable type:    | <int> | <int> | <float> | <float> |
bool GasNode::validate()
{
  std::string tmp;
  size_t start = 0;
  size_t end = string_value.find(' ');
  if (end == std::string::npos)
    return false;

  // get Date.
  tmp = string_value.substr(start, end);
  timestamp = atoi(tmp.c_str());

  // atoi returns 0 on error, 0 isn't a valid timestamp.
  if (timestamp == 0)
    return false;

  start = end + 1;
  end = string_value.find(' ', end + 1 );
  tmp = string_value.substr(start, end - start);
  miles = atoi( tmp.c_str() );

  // miles wont be zero either (even brand new it drives off the lot)
  if (miles == 0)
    return false;

  start = end + 1;
  end = string_value.find(' ', end + 1 );
  tmp = string_value.substr(start, end - start);
  gallons = atof( tmp.c_str() );
  // don't buy no gas.
  if (gallons == 0.0)
    return false;

  start = end + 1;
  end = string_value.find(' ', end + 1 );
  // this should be the last value, so it will return npos.
  if (end != std::string::npos)
    return false;
  tmp = string_value.substr(start);

  price = atof( tmp.c_str() );
  // TODO: this is the only one which might not be true I guess if someone else
  //       pays or you siphon gas off someone else.
  if (price == 0.0)
    return false;

  // parsed all values correctly?  VALID
  return true;
}

time_t GasNode::getDate()
{
  return timestamp;
}

double GasNode::getGallons()
{
  return gallons;
}

int GasNode::getMiles()
{
  return miles;
}

double GasNode::pricePerGallon()
{
  return price;
}

double GasNode::totalPrice()
{
  return price * gallons;
}

