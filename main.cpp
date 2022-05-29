#include "header/ReadFile.h"
#include "header/MenuPos.h"
#include "header/PrintMenu.h"
#include "header/OrderPos.h"
#include "header/Order.h"
int main()
{
    system("clear");
    try
    {
        int choose;
        bool repeat = true;
        Order o;
        do
        {
            o.printMenu();
            std::cin >> choose;
            switch (choose)
            {
            case 0:
                repeat= false;
                break;
            case 1:
                o.addOrderPos();
                break;
            case 2:
                o.deleteOrderPos();
                break;
            case 3:
                o.modifyOrderPos();
                break;
            case 4:
                o.generateBill();
                while (true)
                {
                    /* code */
                }
                
                break;
            default:
                std::cout << "nieprawidłowa wartość!\n(nacisnij dowolny klawisz)\n";
                break;
            }
        } while (repeat);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}