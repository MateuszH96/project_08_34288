#include "../header/Order.h"

uint8_t Order::num = 0;
Order::Order()
{
    numOfOrder=num;
    num = num < 100 ? num++ : 0;
    addOrderPos();
}
Order::~Order()
{
    list.clear();
}

void Order::addOrderPos()
{
    int choose;
    list = std::vector<OrderPos>();
    std::cout<<"wybierz pozycję:\n"<<
                "1.Dodaj zestaw\n"<<
                "2.Dodaj pizzę\n";
    std::cin>>choose;
    OrderPos* input;
    if(choose==1){
        input=new OrderPos(OrderFlag::SET);
        list.push_back(*input);
    }else if(choose == 2){
        OrderPos input2;
        list.push_back(input2);
    }
}

void Order::printOrder()
{
    uint32_t numPos=0;
    for (auto &&i : list)
    {
        std::cout<<numPos<<'.'<<i<<std::endl;
        numPos++;
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