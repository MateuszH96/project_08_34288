//
// Created by mateusz on 30.05.22.
//

#ifndef PIZZATIME_CONVERTSTRING_H
#define PIZZATIME_CONVERTSTRING_H

#include <iostream>
#include <vector>

class ConvertString {
public:
    static std::string cutStringNextChar(std::string input, char sign, unsigned offset = 0);

    static std::vector<std::string> splitStr(std::string input, char sign);
};


#endif //PIZZATIME_CONVERTSTRING_H

