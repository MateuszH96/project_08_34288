#include "../header/ReadFile.h"

std::string ReadFile::getStringFromFile(Flag::Value flags, uint32_t numOfLine)
{

    std::string line = "";
    std::string tmp = "";
    std::ifstream fileToRead(path);
    if (!(fileToRead.is_open()))
    {
        throw FailOpen("Cannot open or does not exist file: " + path + "\n");
    }

    if (flags & Flag::ONE_LINE)
    {
        uint32_t i;
        for (i = 0; i < abs(numOfLine); i++)
        {
            getline(fileToRead, tmp);
        }
        line = tmp;
    }
    else if (flags & Flag::ALL_LINES)
    {
        do
        {
            getline(fileToRead, tmp);
            line += tmp+'\n';
        }while (!(fileToRead.eof()));
    }
    else
    {
        throw InvalidInput("Invalid input!\n");
    }
    fileToRead.close();
    return line;
}
