//
// Created by mateusz on 30.05.22.
//

#include "../header/ConvertString.h"

std::string ConvertString::cutStringNextChar(std::string input, char sign, unsigned int offset) {
    std::string toReturn = "";
    for (int i = 0; i < input.size(); i++) {
        if (input[i] != sign) {
            toReturn += input[i];
        } else {
            for (int j = 0; j < offset; j++) {
                toReturn += input[j + i];
            }
            return toReturn;
        }
    }
    return toReturn;
}

std::vector<std::string> ConvertString::splitStr(std::string input, char sign) {
    std::vector<std::string> vectToReturn;
    std::string stringToVect = "";

    for (auto &&i: input) {
        if (i == sign || i == '\n') {
            vectToReturn.push_back(stringToVect);
            stringToVect = "";
        } else {
            stringToVect += i;
        }

    }
    if (stringToVect.size()) {
        vectToReturn.push_back(stringToVect);
    }
    return vectToReturn;
}