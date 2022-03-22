#include <exception>
#include <iostream>
#ifndef INVALID_INPUT_H
#define INVALID_INPUT_H
class InvalidInput : public std::exception
{
private:
    std::string _message;
public:
    InvalidInput(std::string message) : _message(message){}
    virtual const char* what() const noexcept override
    {
        return _message.c_str();
    }
};
#endif