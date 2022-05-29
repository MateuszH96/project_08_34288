#include "../header/Order.h"
#include "../header/WriteToFile.h"

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
              << "3.Sprawdź zamówienie\n"
              << "4.Generuj Paragon\n";
}

void Order::printOrder() {
    std::cout<<convertOrderToString();
}

void Order::deleteOrderPos() {
    printOrder();
}

void Order::checkOrderPos() {
    char check;
    printOrder();
    std::cout << "wpisz cokolwiek aby kontynuować";
    std::cin >> check;
}

void Order::generateBill() {
    printOrder();
    char confirm;
    std::string filename;
    std::cout << "podaj nazwę rachunku: ";
    std::cin >> filename;
    std::cout << "Czy zakończyłeś zamówienie?(Y/N): ";
    std::cin >> confirm;
    if (toupper(confirm) == 'Y') {
        generateOrderBill(filename);
    }
}

void Order::generateOrderBill(std::string filename) {
    ReadFile rf("../MENU/specialOfferPrice.csv");
    std::vector<std::string> specialOfferPrice = std::vector<std::string>();
    specialOfferPrice = splitPromo(rf.getStringFromFile(Flag::ALL_LINES));
    double totalPrice = getTotalPrice();
    if (std::stod(specialOfferPrice[0])<=totalPrice){
        totalPrice*= std::stod(specialOfferPrice[1]);
    }
    std::string billString=convertOrderToString();
    billString += "\n\n\t\t\tRazem do zapłaty: ";
    billString += std::to_string(totalPrice);
    rf = ReadFile("../MENU/path.txt");
    WriteToFile::saveToFile(rf.getStringFromFile()+filename+".txt",billString);
}

std::vector<std::string> Order::splitPromo(std::string input) {
    std::vector<std::string> toReturn = std::vector<std::string>();
    std::string toPut="";
    for(auto &&i : input){
        if (i!='\n' && i!=EOF){
            toPut+=i;
        }else{
            toReturn.push_back(toPut);
            toPut="";
        }
    }
    return toReturn;
}
double Order::getTotalPrice() {
    double sum=0.0;
    for(auto &&i:list){
        for(auto &&j : i){
            sum+=j.price;
        }
    }
    return sum;
}
std::string Order::convertOrderToString() {
    std::string toReturn = "";
    for(int i = 0; i<list.size();i++){
        toReturn+=list[i][0].name+"\t"+std::to_string(list[i][0].price)+"\n";
        for (int j = 1; j < list[i].size(); j++) {
            toReturn+="\t\t\t\t"+list[i][j].name+"\t"+std::to_string(list[i][j].price)+"\n";
        }
    }
    return toReturn;
}