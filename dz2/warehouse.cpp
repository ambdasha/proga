#include "warehouse.h"

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

void input_max_products(int &n)
{
    do {cout<< "Max products: "; cin>>n;} 
    while (n <= 0);
}

Warehouse::Warehouse()
{
    this->index = 100;
    this->side = CENTER;
    this->longitude = 0.0;
    this->lattitude = 0.0;
    this->capacity = 0;
    this->amount = 0;
    this->size = 0;
    this->list = nullptr;
}

Warehouse::Warehouse( int index, SIDE side, double longitude, double lattitude, int capacity, int n)
{
    if (100 + index > 999) {cout<< "Unable to give such a code.";}
    else {this->index = 100 + index;}

    this->side = side;
    this->longitude = longitude;
    this->lattitude = lattitude;
    this->capacity = capacity;
    this->amount = capacity;
    this->size = 0;
    this->list = new Product[n];
}

Warehouse::Warehouse(const Warehouse &w)
{
    this->index = w.index;
    this->side = w.side;
    this->longitude = w.longitude;
    this->lattitude = w.lattitude;
    this->capacity = w.capacity;
    this->amount = w.amount;
    this->size = w.size;
    this->list = new Product[w.size];

    for (int i = 0; i < w.size; i++) {this->list[i] = w.list[i];}
}

Warehouse::~Warehouse()
{
    delete[] this->list;
}


void Warehouse::set_size(int n){
    this->size = n;
}

int Warehouse::get_size(){
    return this->size;
}


void Warehouse::insert_product(char description[50], double cost, int amount, double longitude, double lattitude){
    this->list[this->size].code = (1 + rand() % 2) * 1000000000 + (1 + rand() % 999999);

    strcpy(this->list[this->size].description, description);

    this->list[this->size].cost = cost;

    this->list[this->size].amount = amount;

    if (this->list[this->size].amount > this->amount){
        this->list[this->size].amount = this->amount;
        this->amount = 0;
    } else {this->amount = this->capacity - this->list[this->size].amount;}

    this->list[this->size].longitude = longitude;
    
    this->list[this->size].lattitude = lattitude;
    
    this->size++;
    this->set_size(this->size);
}


Product Warehouse::get_product(int pos){
    return this->list[pos];
}

void Warehouse::print_list(){
    cout<< setw(15) << "Code" <<
    setw(15) << "Description" <<
    setw(10) << "Cost" <<
    setw(10) << "Amount" <<
    setw(10) << "Longitude" <<
    setw(10) << "Lattitude" <<endl;

    for (int i = 0; i < this->size; i++){
        this->list[i].print();
    }
}

int Warehouse::search_product(char search_criteria[50]){
    int pos;
    for (int i = 0; i < this->get_size(); i++){
        if (strcmp(this->list[i].description, search_criteria) == 0) {pos = i; return pos;}
    }

    return -1;
}

void Warehouse::delete_product(char search_criteria[50]){
    int pos = this->search_product(search_criteria);

    if (pos != -1){
        this->amount = this->amount + this->list[pos].amount;
        
        for (int i = pos; i < this->get_size()-1; i++){
            this->list[i] = this->list[i+1];
        }
        this->size--;
        this->set_size(this->size);
        cout<< "Product deleted" <<endl;
           
    } else {cout<< "Product not found!" <<endl;}
}


double calculate_dist(Warehouse w, double longitude, double lattitude){
    return abs(w.longitude - longitude) + abs(w.lattitude - lattitude);
}

void insert_new_product(Warehouse list[3]){
    char description[50];
    int amount;
    double cost, longitude, lattitude;
    cout<< "Insert new product" <<endl;

    cout<< "Description: "; cin>> description;

    do{
        cout<< "Cost: "; cin>> cost;
    } while (cost < 0);

    do{
        cout<< "Amount: "; cin>> amount;
    } while (amount <= 0);

    do{
        cout<< "Longitude: "; cin>> longitude;
    } while (longitude < 19 || longitude > 169);

    do{
        cout<< "Lattitude: "; cin>> lattitude;
    } while (lattitude < 41 || lattitude > 82);

    if (calculate_dist(list[0], longitude, lattitude) < calculate_dist(list[1], longitude, lattitude) 
    && calculate_dist(list[0], longitude, lattitude) < calculate_dist(list[2], longitude, lattitude)){
        if (list[0].amount > 0){
            list[0].insert_product(description, cost, amount, longitude, lattitude);
        }else if (calculate_dist(list[1], longitude, lattitude) <= calculate_dist(list[2], longitude, lattitude)){
            if (list[1].amount > 0){
                list[1].insert_product(description, cost, amount, longitude, lattitude);
            } 
        }else if (calculate_dist(list[1], longitude, lattitude) > calculate_dist(list[2], longitude, lattitude)){
            if (list[2].amount > 0){
                list[2].insert_product(description, cost, amount, longitude, lattitude);
            }
        }else {cout<< "Unable to insert in warehouse!" <<endl;}
    }

    if (calculate_dist(list[1], longitude, lattitude) < calculate_dist(list[0], longitude, lattitude) 
    && calculate_dist(list[1], longitude, lattitude) < calculate_dist(list[2], longitude, lattitude)){
        if (list[1].amount > 0){
            list[1].insert_product(description, cost, amount, longitude, lattitude);
        }else if (calculate_dist(list[0], longitude, lattitude) <= calculate_dist(list[2], longitude, lattitude)){
            if (list[0].amount > 0){
                list[0].insert_product(description, cost, amount, longitude, lattitude);
            } 
        }else if (calculate_dist(list[0], longitude, lattitude) > calculate_dist(list[2], longitude, lattitude)){
            if (list[2].amount > 0){
                list[2].insert_product(description, cost, amount, longitude, lattitude);
            }
        }else {cout<< "Unable to insert in warehouse!" <<endl;}
    }

    if (calculate_dist(list[2], longitude, lattitude) < calculate_dist(list[0], longitude, lattitude) 
    && calculate_dist(list[2], longitude, lattitude) < calculate_dist(list[1], longitude, lattitude)){
        if (list[2].amount > 0){
            list[2].insert_product(description, cost, amount, longitude, lattitude);
        }else if (calculate_dist(list[0], longitude, lattitude) <= calculate_dist(list[1], longitude, lattitude)){
            if (list[0].amount > 0){
                list[0].insert_product(description, cost, amount, longitude, lattitude);
            } 
        }else if (calculate_dist(list[0], longitude, lattitude) > calculate_dist(list[1], longitude, lattitude)){
            if (list[1].amount > 0){
                list[1].insert_product(description, cost, amount, longitude, lattitude);
            }
        }else {cout<< "Unable to insert in warehouse!" <<endl;}
    }
}

void search_product(Warehouse list[3]){
    char search_criteria[50];
    cout<< "Search criteria: "; cin>> search_criteria;

    for (int i = 0; i < 3; i++){
        cout<< "---------------" << list[i].code_letter << list[i].index << "---------------" <<endl;
        if (list[i].search_product(search_criteria) != -1){
            list[i].get_product(list[i].search_product(search_criteria)).print();
        } else {cout<< "Product not found!" << endl;}
    }
}



void delete_product(Warehouse list[3]){
    int opt;
    char search_criteria[50];
    do{
        cout << "Choose warehouse: "; cin>> opt;
    } while (opt < 1 && opt > 3);

    cout<< "Search criteria: "; cin>> search_criteria;

    switch (opt)
    {
    case 1:
        list[0].delete_product(search_criteria);
        break;
    case 2:
        list[1].delete_product(search_criteria);
        break;
    case 3:
        list[2].delete_product(search_criteria);
        break;
    }
}

void print_list(Warehouse list[3]){
    int opt;
    do{
        cout << "Choose warehouse: "; cin>> opt;
    } while (opt < 1 && opt > 3);

    switch (opt)
    {
    case 1:
        list[0].print_list();
        break;
    case 2:
        list[1].print_list();
        break;
    case 3:
        list[2].print_list();
        break;
    }  
}

void menu(int &opt)
{
    cout<<left;
    cout<<"--------------------"<<endl;
    cout<<"MENU OF WAREHOUSES"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"[1]. Insert product"<<endl;
    cout<<"[2]. Print list of products"<<endl;
    cout<<"[3]. Search product by description"<<endl;
    cout<<"[4]. Delete product"<<endl;
    cout<<"[5]. Exit"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Enter option: "; cin>>opt;  
}
