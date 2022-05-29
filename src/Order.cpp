#include "../header/Order.h"

uint8_t Order::num = 0;

Order::Order() {
    list = std::vector<std::vector<Ingredient>>();
    numOfOrder = num;
    num = num < 100 ? num++ : 0;
}

Order::~Order() {
    list.clear();
}

void Order::addOrderPos() {
    OrderPos *orderPos;
    int input;
    system("clear");
    std::cout << "Wybierz pozyceję:\n"
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
    orderPos = NULL;

}

void Order::printMenu() {
    //system("clear");
    std::cout << "Wybierz pozyceję:\n"
              << "0.Zakończ\n"
              << "1.Dodaj pozycję\n"
              << "2.Usuń pozycję\n"
              << "3.Modyfikuj\n"
              << "4.Generuj Paragon\n";
}

void Order::printOrder() {
    for (unsigned i = 0; i < list.size(); i++) {
        std::cout << list[i][0].name << " - " << list[i][0].price<<std::endl;
        for (unsigned j = 1; j < list[i].size(); ++j) {
            std::cout<<"\t\t\t\t"<< list[i][j].name << " - " << list[i][j].price<<std::endl;
        }
    }
}

void Order::deleteOrderPos() {
    printOrder();
}

void Order::modifyOrderPos() {
    printOrder();
}

void Order::generateBill() {
    printOrder();
}