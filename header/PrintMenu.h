//
// Created by mateusz on 29.05.22.
//

#ifndef PIZZATIME_PRINTMENU_H
#define PIZZATIME_PRINTMENU_H

#include "MenuPos.h"
#include "ReadFile.h"
#include <iostream>
#include <vector>
#include "ConvertString.h"

class PrintMenu {
private:
    const std::string path = "../MENU/";
    std::vector<MenuPos> menu;
    std::string filePath;
public:
    PrintMenu(std::string file);

    ~PrintMenu();

    std::vector<MenuPos> getMenuList();

    PrintMenu operator=(const PrintMenu &pm);

    void print();
};

#endif //PIZZATIME_PRINTMENU_H
