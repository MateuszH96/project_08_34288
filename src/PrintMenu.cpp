#include "../header/PrintMenu.h"

PrintMenu::PrintMenu(std::string file) {
    filePath = path + file;
    Read *fileToRead = new ReadFile(filePath);
    std::vector<std::string> listMenu = ConvertString::splitStr(fileToRead->getStringFromFile(Flag::ALL_LINES), '\n');
    for (auto &&i: listMenu) {
        menu.push_back(MenuPos(i));;
    }
    listMenu.clear();
}

PrintMenu::~PrintMenu() {
    menu.clear();
}

void PrintMenu::print() {
    for (auto &&i: menu) {
        std::cout << i << std::endl;
    }
}


std::vector<MenuPos> PrintMenu::getMenuList() {
    return menu;
}

PrintMenu PrintMenu::operator=(const PrintMenu &pm) {
    menu = pm.menu;
    filePath = pm.filePath;
    return *this;
}
