//
// Created by mateusz on 29.05.22.
//

#include <fstream>
#include "../header/WriteToFile.h"

void WriteToFile::saveToFile(std::string path, std::string content) {
    std::ofstream file(path);
    if (!file.is_open()){
        throw FailOpen("Cannot open file: " + path + "\n");
    }
    file<<content;
    file.close();
}
