#pragma once
#include "product.h"

enum SIDE{CENTER, WEST, EAST};

class Warehouse
{
    public:
        char code_letter = 'W';
        unsigned int index;
        SIDE side;
        double longitude, lattitude;
        int capacity, amount, size;
        Product* list;

    public:
        Warehouse();
        Warehouse(int index, SIDE side, double longitude, double lattitude, int capacity, int n);
        Warehouse(const Warehouse &w);
        ~Warehouse();
        void set_size(int n);
        int get_size();
        Product get_product(int pos);
        void menu(int &opt);
        void insert_product(char description[50], double cost, int amount, double longitude, double lattitude);
        void print_list();
        int search_product(char search_criteria[50]);
        void delete_product(char search_criteria[50]);
};

void input_max_products(int &n);
double calculate_dist(Warehouse w, double longitude, double lattitude);
void insert_new_product(Warehouse list[3]);
void search_product(Warehouse list[3]);
void delete_product(Warehouse list[3]);
void print_list(Warehouse list[3]);
void menu(int &opt);