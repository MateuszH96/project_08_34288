<<<<<<< Updated upstream
=======
<<<<<<< Updated upstream
#ifndef PRINT_MENU_H
#define PRINT_MENU_H
=======
>>>>>>> Stashed changes
//
// Created by mateusz on 29.05.22.
//

#ifndef PIZZATIME_PRINTMENU_H
#define PIZZATIME_PRINTMENU_H
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
>>>>>>> Stashed changes
#include "MenuPos.h"
#include "ReadFile.h"
#include <iostream>
#include <vector>
#include "ConvertString.h"

class PrintMenu {
private:
<<<<<<< Updated upstream
    const std::string path="../MENU/";
=======
<<<<<<< Updated upstream
    const std::string path="../MENU/"; 
=======
    const std::string path = "../MENU/";
>>>>>>> Stashed changes
>>>>>>> Stashed changes
    std::vector<MenuPos> menu;
    std::string filePath;
public:
    PrintMenu(std::string file);

    ~PrintMenu();

    std::vector<MenuPos> getMenuList();

    PrintMenu operator=(const PrintMenu &pm);

    void print();
};
<<<<<<< Updated upstream
#endif //PIZZATIME_PRINTMENU_H
=======
<<<<<<< Updated upstream
#endif
=======

#endif //PIZZATIME_PRINTMENU_H
>>>>>>> Stashed changes
>>>>>>> Stashed changes
