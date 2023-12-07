#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
#include <iostream>
class CException
{
protected:
    // int fm1 = 0;
public:
    CException(const char *errorMessage) : message(errorMessage) {}
    const char *what() const
    {
        return message.c_str();
    }

private:
    /* data */
    // int fm2 = 0;
    std::string message;
};

#endif