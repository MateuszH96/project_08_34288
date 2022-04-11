#include "../header/OrderPos.h"

OrderPos::OrderPos(OrderFlag::Value flag)
{
    menu = new PrintMenu("dough.csv");
    if (flag & OrderFlag::SET)
    {
        menu = new PrintMenu("set.csv");
    }
    price=0.0;
    pickPos();
}
OrderPos::~OrderPos()
{
    list.clear();
    delete menu;
}
void OrderPos::pickPos()
{
    uint32_t pos;
    double pricePos;
    char size;
    do
    {
        system("clear");
        menu->print();
        std::cout<<"Aby wyjść podaj 0"<<std::endl;
        std::cout << "Podaj numer pozycji: ";
        std::cin >> pos;
        if (pos >= menu->getMenuList().size() || pos <= 0)
        {
            return;
        }
        else
        {
            std::cout << "Podaj wielkość(S/M/L): ";
            std::cin >> size;
            switch (toupper(size))
            {
            case 'S':
                pricePos = menu->getMenuList()[pos].getSmallSize();
                break;
            case 'M':
                pricePos = menu->getMenuList()[pos].getMediumSize();
                break;
            case 'L':
                pricePos = menu->getMenuList()[pos].getLargeSize();
                break;
            default:
                return;
            }
            list.push_back(Ingredient(menu->getMenuList()[pos].getName(), pricePos));
            price+=pricePos;
        }
        delete menu;
        menu = new PrintMenu("ingredient.csv");
    } while (true);
    return;
}
void OrderPos::addIngredient()
{
    menu = new PrintMenu("ingredient.csv");
    pickPos();
}

void OrderPos::removeIngredient()
{
    uint32_t pos;
    std::cout << *this << std::endl;

    std::cout << "podaj numer dodatku do usunięcia: ";
    std::cin >> pos;
    if (pos > 0 && pos < list.size())
    {
        price-=list[pos].price;
        list.erase(list.begin() + pos);
    }
}
std::ostream &operator<<(std::ostream &out, const OrderPos &input)
{
    out << input.list[0].name << '\t' << input.list[0].price << std::endl;
    uint32_t i;
    for (i = 1; i < input.list.size(); i++)
    {
        out << '\t' << i << ". " << input.list[i].name << '\t' << input.list[i].price << std::endl;
    }
    return out;
}