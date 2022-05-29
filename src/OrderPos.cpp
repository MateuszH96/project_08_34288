#include "../header/OrderPos.h"

OrderPos::OrderPos(TYPE_POS typePos)
{
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
        menu = new PrintMenu("set.csv");
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
            std::cout << "Podaj rozmiar(S/M/L): ";
            std::cin >> size;
            std::string sizeToAdd(1,size);
            double priceSize = getPriceBySize(size, input-1);
            if (priceSize)
            {
                toAdd = ingredient(menu->getMenuList()[input - 1].getName(), priceSize);
                switch (typePos)
                {
                case PIZZA:
                    list.push_back(toAdd);
                        char doRepeat;
                    do
                    {
                        addAdditives("ingredient.csv");
                        std::cout<<"Czy dodać kolejne dodatki?(Y/N)";
                        std::cin>>doRepeat;
                    } while (toupper(doRepeat)=='Y');
                    repeat = false;
                    break;
                case HALF_PIZZA:
                    halfPizza(toAdd, size);
                    list.push_back(toAdd);
                    repeat = false;
                    break;
                case SET:
                    toAdd.name = sizeToAdd+ "-" + toAdd.name;
                    list.push_back(toAdd);
                    repeat = false;
                    break;
                case PIZZA_AND_DRINK:
                    toAdd.name = "P+D - " + toAdd.name;
                    list.push_back(toAdd);
                    addAdditives("set.csv");
                    addAdditives("drinks.csv");
                    list[list.size()-1].price=0.0;
                    repeat = false;
                    break;
                }
            }
        }
        else if (input == 0)
        {
            return;
        }
    } while (repeat);
    isAdded =true;
}
void OrderPos::addAdditives(std::string file)
{
    delete menu;
    unsigned input;
    menu = new PrintMenu(file);
    system("clear");
    menu->print();
    bool repeat = true;
    do
    {
        std::cout << "Podaj numer pozycji: ";
        std::cin >> input;
        if (input > 0 && input <= menu->getMenuList().size())
        {
            char size;
            std::cout << "Podaj wielkość porcji(S/M/L): ";
            std::cin >> size;
            double priceSize = getPriceBySize(size, input-1);
            if (priceSize)
            {
                ingredient toAdd(menu->getMenuList()[input - 1].getName(), priceSize);
                list.push_back(toAdd);
                repeat = false;
            }
        }
        else if (input == 0)
        {
            repeat = false;
        }
        else
        {
            std::cout << "nieprawidłowa wartość!\n";
        }

    } while (repeat);
}
void OrderPos::halfPizza(ingredient &toAdd, char size)
{
    menu->print();
    toAdd.price = setPrecision(toAdd.price / 2.0, 2);
    unsigned input=0;
    bool repeat = true;
    do
    {
        std::cin >> input;
        if (input > 0 && input <= menu->getMenuList().size())
        {
            toAdd.name +="+" + menu->getMenuList()[input - 1].getName();
            toAdd.price += setPrecision((getPriceBySize(size, input - 1) / 2.0), 2);
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
    //std::cout << *this << std::endl;

    std::cout << "podaj numer dodatku do usunięcia: ";
    std::cin >> pos;
    if (pos > 0 && pos < list.size())
    {
        list.erase(list.begin() + pos);
    }
}
double OrderPos::getPriceBySize(char size, unsigned index)
{
    std::map<char, double> dirSize = {
        {'s', menu->getMenuList()[index].getSmallSize()},
        {'S', menu->getMenuList()[index].getSmallSize()},
        {'m', menu->getMenuList()[index].getMediumSize()},
        {'M', menu->getMenuList()[index].getMediumSize()},
        {'l', menu->getMenuList()[index].getLargeSize()},
        {'L', menu->getMenuList()[index].getLargeSize()}};
    return dirSize[size];
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
    unsigned i;
    for (i = 1; i < input.list.size(); i++)
    {
        out << '\t' << i << ". " << input.list[i].name << '\t' << input.list[i].price<< "zł" << std::endl;
    }
    return out;
}
std::vector<Ingredient> OrderPos::getList() {
    return list;
}