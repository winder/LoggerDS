#ifndef STRINGEXCEPTION_H
#define STRINGEXCEPTION_H

#include <exception>
#include <string>

/*
struct StringException : public std::exception
{
   std::string s;
   StringException(std::string ss) : s(ss) {}
   const char* what() const throw() { return s.c_str(); }
};
*/

class StringException : public std::exception
{
  public:
    StringException ( const std::string& msg)  
      throw () : usrMsg(msg) {  }
    ~StringException ( )  
      throw () { }
    const char *what() const throw() { return usrMsg.c_str(); }
  private:
    std::string usrMsg;
};



#endif
