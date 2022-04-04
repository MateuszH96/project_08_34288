#include "../header/PrintMenu.h"

PrintMenu::PrintMenu(std::string file)
{
    filePath=path+file;
    Read* fileToRead=new ReadFile(filePath);
    std::vector<std::string> listMenu=splitStr(fileToRead->getStringFromFile(Flag::ALL_LINES));
    for (auto &&i : listMenu)
    {
        menu.push_back(MenuPos(i));;
    }
    listMenu.clear();
}
PrintMenu::~PrintMenu()
{
    menu.clear();
}
std::vector<std::string> PrintMenu::splitStr(std::string toSplit)
{
    std::vector<std::string> vectToReturn;
    std::string stringToVect="";

    for (auto &&i : toSplit)
    {
        if (i=='\n')
        {
            vectToReturn.push_back(stringToVect);
            stringToVect="";
        }else
        {
            stringToVect+=i;
        }
        
    }
    return vectToReturn;
}

void PrintMenu::print()
{
    for (auto &&i : menu)
    {
        std::cout<<i<<std::endl;
    }
}

std::vector<MenuPos> PrintMenu::getMenuList()
{
    return menu;
}

PrintMenu PrintMenu::operator=(const PrintMenu& pm)
{
    menu=pm.menu;
    filePath=pm.filePath;
    return *this;
}
