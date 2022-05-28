#include "../header/OrderPos.h"
#include <iomanip>
OrderPos::OrderPos(TYPE_POS typePos)
{
    price = 0.0;
    isAdded = false;
    list = std::vector<Ingredient>();
    if (typePos != ERROR)
    {
        pickPos(typePos);
    }
}
OrderPos::~OrderPos()
{
    list.clear();
    delete menu;
}
void OrderPos::pickPos(TYPE_POS typePos)
{

    switch (typePos)
    {
    case PIZZA:
        menu = new PrintMenu("dough.csv");
        break;
    case HALF_PIZZA:
    case SET:
        menu = new PrintMenu("set.csv");
        break;
    case PIZZA_AND_DRINK:
        break;
    case INGREDIENTS:
        menu = new PrintMenu("ingredient.csv");
        break;
    default:
        break;
    }
    addPos(typePos);
    delete menu;
}
void OrderPos::addPos(TYPE_POS typePos)
{
    ingredient toAdd;
    unsigned input;
    char size;
    bool repeat = true;
    do
    {
        system("clear");
        menu->print();
        std::cout << "0. Powrót\n";
        std::cout << "Wybierz numer pozycji: ";
        std::cin >> input;

        if (input > 0 && input <= menu->getMenuList().size())
        {
            std::map<char, double> dirSize = {
                {'s', menu->getMenuList()[input - 1].getSmallSize()},
                {'S', menu->getMenuList()[input - 1].getSmallSize()},
                {'m', menu->getMenuList()[input - 1].getMediumSize()},
                {'M', menu->getMenuList()[input - 1].getMediumSize()},
                {'l', menu->getMenuList()[input - 1].getLargeSize()},
                {'L', menu->getMenuList()[input - 1].getLargeSize()}};
            std::cout << "Podaj rozmiar(S/M/L): ";
            std::cin >> size;
            if (dirSize[size])
            {
                toAdd = ingredient(menu->getMenuList()[input - 1].getName(), dirSize[size]);
                switch (typePos)
                {
                case PIZZA:
                    break;
                case HALF_PIZZA:
                    toAdd.name="50/50-"+toAdd.name;
                    halfPizza(toAdd, size);
                case SET:
                    repeat = false;
                    break;
                case PIZZA_AND_DRINK:
                    break;
                case INGREDIENTS:
                    break;
                }
            }
        }
        else if (input == 0)
        {
            return;
        }
    } while (repeat);
    std::cout << toAdd.name << "----" << toAdd.price << std::endl;
    while (true)
        ;

    list.push_back(toAdd);
}
void OrderPos::addIngredient()
{
    pickPos(INGREDIENTS);
}
void OrderPos::halfPizza(ingredient &toAdd, char size)
{
    toAdd.name += "+";
    // toAdd.price /= 2.0;
    toAdd.price = setPrecision(toAdd.price / 2.0, 2);
    unsigned input;
    bool repeat = true;
    do
    {
        std::cout << "Podaj drugą połowę: ";
        std::cin >> input;
        if (input > 0 && input <= menu->getMenuList().size())
        {
            std::map<char, double> dirSize = {
                {'s', menu->getMenuList()[input - 1].getSmallSize()},
                {'S', menu->getMenuList()[input - 1].getSmallSize()},
                {'m', menu->getMenuList()[input - 1].getMediumSize()},
                {'M', menu->getMenuList()[input - 1].getMediumSize()},
                {'l', menu->getMenuList()[input - 1].getLargeSize()},
                {'L', menu->getMenuList()[input - 1].getLargeSize()}};
            toAdd.name += menu->getMenuList()[input - 1].getName();
            std::cout << toAdd.price << std::endl;
            toAdd.price += setPrecision((dirSize[size] / 2.0), 2);
            std::cout << toAdd.price << std::endl;
            repeat = false;
        }
        else
        {
            std::cout << "nieprawidłowa wartość!\n";
        }
    } while (repeat);
}
void OrderPos::removeIngredient()
{
    unsigned pos;
    std::cout << *this << std::endl;

    std::cout << "podaj numer dodatku do usunięcia: ";
    std::cin >> pos;
    if (pos > 0 && pos < list.size())
    {
        price -= list[pos - 1].price;
        list.erase(list.begin() + pos);
    }
}

bool OrderPos::getIsAdded()
{
    return isAdded;
}
double OrderPos::setPrecision(double input, unsigned n)
{
    return std::ceil(input * (pow(10.0, n))) / (pow(10.0, n));
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
