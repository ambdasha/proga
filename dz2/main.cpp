#include <iostream>
#include "product.cpp"
#include "warehouse.cpp"

using namespace std;

int main()
{
    int n, opt;
    input_max_products(n);
    Warehouse w_c(1, CENTER, 50, 55, 100, n);
    Warehouse w_w(2, WEST, 70, 90, 150, n);
    Warehouse w_e(3, EAST, 90, 68, 50, n);
    Warehouse list[3] = {w_c, w_w, w_e};

    do{
        menu(opt);

        switch (opt)
        {
            case 1:
                insert_new_product(list);
                break;
            case 2:
                print_list(list);
                break;
            case 3:
                search_product(list);
                break;
            case 4:
                delete_product(list);
                break;
            case 5:
                cout<< "Exit from programm!" <<endl;
                break;
            default:
                cout<< "Invalid option!" <<endl;
        }
    } while (opt != 5);

    cout<< "Programm is over!" <<endl;

    return 0;
}
