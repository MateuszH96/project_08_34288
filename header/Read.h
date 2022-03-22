#ifndef READ_H
#define READ_H
#include <iostream>

typedef struct flag
{
    enum Value{
        ONE_LINE=0x01,
        ALL_LINES=0x02
    };
}Flag;

class Read
{
protected:
    std::string path;
public:
    Read(std::string _path) :  path(_path){}
    virtual std::string getStringFromFile(Flag::Value flags=flag::ONE_LINE,uint32_t numOfLine=1)=0;
};
#endif