#include "../header/Order.h"
uint8_t Order::num = 0;
Order::Order()
{
    list=std::vector<OrderPos>();
    numOfOrder=num;
    num = num < 100 ? num++ : 0;
}
Order::~Order()
{
    list.clear();
}

void Order::addOrderPos()
{
    OrderPos orderPos();
    system("clear");
    std::cout   <<"Wybierz pozyceję:\n"<<
                "1.Dodaj Pizzę\n"<<
                "2.Dodaj Zestaw\n"<<
                "3.Pizza 50/50\n"<<
                "4. 2x Pizza + napój gratis\n";
    
}
void Order::printMenu(){
    system("clear");
    std::cout   <<"Wybierz pozyceję:\n"<<
                "0.Zakończ\n"<<
                "1.Dodaj pozycję\n"<<
                "2.Usuń pozycję\n"<<
                "3.Modyfikuj\n"<<
                "4.Generuj Paragon\n";
}
void Order::printOrder()
{
    uint32_t numPos=0;
    for (auto &&i : list)
    {
        std::cout<<++numPos<<'.'<<i<<std::endl;
    }
}

void Order::deleteOrderPos()
{
    printOrder();
}

void Order::modifyOrderPos()
{
    printOrder();
}
void Order::generateBill(){

}