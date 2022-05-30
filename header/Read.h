<<<<<<< Updated upstream
=======
<<<<<<< Updated upstream
#ifndef READ_H
#define READ_H
=======
>>>>>>> Stashed changes
//
// Created by mateusz on 29.05.22.
//

#ifndef PIZZATIME_READ_H
#define PIZZATIME_READ_H
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
>>>>>>> Stashed changes
#include <iostream>

typedef struct flag {
    enum Value {
        ONE_LINE = 0x01,
        ALL_LINES = 0x02
    };
} Flag;

class Read {
protected:
    std::string path;
public:
    Read(std::string _path) : path(_path) {}

    virtual std::string getStringFromFile(Flag::Value flags = flag::ONE_LINE, uint32_t numOfLine = 1) = 0;
};
<<<<<<< Updated upstream
#endif //PIZZATIME_READ_H
=======
<<<<<<< Updated upstream
#endif
=======

#endif //PIZZATIME_READ_H
>>>>>>> Stashed changes
>>>>>>> Stashed changes
