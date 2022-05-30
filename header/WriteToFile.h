//
// Created by mateusz on 29.05.22.
//

#ifndef PIZZATIME_WRITETOFILE_H
#define PIZZATIME_WRITETOFILE_H

#include "../exceptions/FailOpen.h"
#include <iostream>

class WriteToFile {
public:
    static void saveToFile(std::string path, std::string content);
};


#endif //PIZZATIME_WRITETOFILE_H
