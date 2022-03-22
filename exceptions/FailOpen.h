#include <exception>
#include <iostream>
#ifndef FAIL_OPEN_H
#define FAIL_OPEN_H
class FailOpen : public std::exception
{
private:
    std::string _message;
public:
    FailOpen(std::string message) : _message(message){}
    virtual const char* what() const noexcept override
    {
        return _message.c_str();
    }
};
#endif