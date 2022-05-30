//
// Created by mateusz on 29.05.22.
//

#include <fstream>
#include "../header/WriteToFile.h"

void WriteToFile::saveToFile(std::string path, std::string content) {
    std::ofstream file(path);
<<<<<<< Updated upstream
<<<<<<< Updated upstream
    if (!file.is_open()){
        throw FailOpen("Cannot open file: " + path + "\n");
    }
    file<<content;
=======
=======
>>>>>>> Stashed changes
    if (!file.is_open()) {
        throw FailOpen("Cannot open file: " + path + "\n");
    }
    file << content;
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
    file.close();
}
