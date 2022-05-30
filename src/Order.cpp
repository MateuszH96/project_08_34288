#include "../header/Order.h"
#include "../header/WriteToFile.h"


Order::Order() {
    list = std::vector<std::vector<Ingredient>>();
}

Order::~Order() {
    list.clear();
}

void Order::addOrderPos() {
    OrderPos *orderPos;
    int input;
    system("clear");
    std::cout << "Wybierz pozycję:\n"
              << "0.Powrót\n"
              << "1.Dodaj Pizzę\n"
              << "2.Dodaj Zestaw\n"
              << "3.Pizza 50/50\n"
              << "4.2x Pizza + napój gratis\n";
    std::cin >> input;
    switch (input) {
        case 0:
            return;
        case 1:
            orderPos = new OrderPos(PIZZA);
            break;
        case 2:
            orderPos = new OrderPos(SET);
            break;
        case 3:
            orderPos = new OrderPos(HALF_PIZZA);
            break;
        case 4:
            orderPos = new OrderPos(PIZZA_AND_DRINK);
            break;
        default:
            orderPos = new OrderPos(ERROR);
            std::cout << "nieprawidłowa wartość!\n(nacisnij dowolny klawisz)\n";
            break;
    }


    if (orderPos->getIsAdded()) {
        this->list.push_back(orderPos->getList());
    }
    orderPos = nullptr;

}

void Order::printMenu() {
    system("clear");
    std::cout << "Wybierz pozycję:\n"
              << "0.Zakończ\n"
              << "1.Dodaj pozycję\n"
              << "2.Usuń pozycję\n"
              << "3.Sprawdź zamówienie\n"
              << "4.Generuj Paragon\n";
}

void Order::printOrder() {
    system("clear");
    std::cout << convertOrderToString();
}

void Order::deleteOrderPos() {
    system("clear");
    bool repeat = true;
    do{
        printOrder();
        std::cout<<"0.Powrót\n";
        std::cout << "Podaj numer do usunięcia: ";
        unsigned input;
        std::cin >> input;
        if (input > 0 && input<=list.size()){
            list.erase(list.begin()+input-1);
        }else if(!input){
            repeat=false;
        }else{
            std::cout<<"Nieprawidłowa wartość!\n";
        }
    }while(repeat);
}

void Order::checkOrderPos() {
    std::string check;
    printOrder();
    std::cout << "wpisz cokolwiek aby kontynuować";
    std::cin >> check;
}

void Order::generateBill() {
    printOrder();
    char confirm;
    std::cout << "Czy zakończyłeś zamówienie?(Y/N): ";
    std::cin >> confirm;
    if (toupper(confirm) == 'Y') {
        std::string filename;
        std::cout << "podaj nazwę rachunku: ";
        std::cin >> filename;
        generateOrderBill(filename);
    }
}

void Order::generateOrderBill(const std::string &filename) {
    ReadFile rf("../MENU/specialOfferPrice.csv");
    std::vector<std::string> specialOfferPrice = std::vector<std::string>();
    specialOfferPrice = splitPromo(rf.getStringFromFile(Flag::ALL_LINES));
    double totalPrice = getTotalPrice();
    if (std::stod(specialOfferPrice[0]) <= totalPrice) {
        totalPrice *= std::stod(specialOfferPrice[1]);
    }
    std::string billString = convertOrderToString();
    billString += "\n\n\t\t\tRazem do zapłaty: ";
    billString += ConvertString::cutStringNextChar(std::to_string(totalPrice), '.', 3)+"zł";
    rf = ReadFile("../MENU/path.txt");
    WriteToFile::saveToFile(rf.getStringFromFile() + filename + ".txt", billString);
}

std::vector<std::string> Order::splitPromo(const std::string &input) {
    std::vector<std::string> toReturn = std::vector<std::string>();
    std::string toPut;
    for (auto &&i: input) {
        if (i != '\n' && i != EOF) {
            toPut += i;
        } else {
            toReturn.push_back(toPut);
            toPut = "";
        }
    }
    return toReturn;
}

double Order::getTotalPrice() {
    double sum = 0.0;
    for (auto &&i: list) {
        for (auto &&j: i) {
            sum += j.price;
        }
    }
    return sum;
}

std::string Order::convertOrderToString() {
    std::string toReturn;
    for (int i = 0; i < list.size(); i++) {
        toReturn += std::to_string(i + 1) + "." + list[i][0].name + "\t"
                    + ConvertString::cutStringNextChar(std::to_string(list[i][0].price), '.', 3)+"zł"+ "\n";
        for (int j = 1; j < list[i].size(); j++) {
            toReturn += "\t\t\t\t" + list[i][j].name + "\t" +
                        ConvertString::cutStringNextChar(std::to_string(list[i][j].price), '.', 3)+"zł"+ "\n";
        }
    }
    return toReturn;
}

