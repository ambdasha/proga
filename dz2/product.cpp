#include <iostream>
#include <cstring>
#include <iomanip>
#include "product.h"

using namespace std;

Product::Product()
{
    this->code = -1;
    strcpy(this->description, "");
    this->cost = 0.0;
    this->amount = 0;
    this->longitude = 0.0;
    this->lattitude = 0.0;
}

Product::Product(char description[50], double cost, int amount, double longitude, double lattitude)
{
    this->code = (1 + rand() % 2) * 1000000000 + (1 + rand() % 999999);
    strcpy(this->description, description);
    this->cost = cost;
    this->amount = amount;
    this->longitude = validate_component(longitude, 19, 169);
    this->lattitude = validate_component(lattitude, 41, 82);
}

Product::Product(const Product &p)
{
    this->code = p.code;
    strcpy(this->description, p.description);
    this->cost = p.cost;
    this->amount = p.amount;
    this->longitude = p.longitude;
    this->lattitude = p.lattitude;
}

Product::~Product(){}

void Product::set(char description[50], double cost, int amount, double longitude, double lattitude)
{
    strcpy(this->description, description);
    this->cost = cost;
    this->amount = amount;
    this->longitude = validate_component(longitude, 19, 169);
    this->lattitude = validate_component(lattitude, 41, 82);
}


void Product::get(int &code, char* &description, double &cost, int &amount, double &longitude, double &lattitude)
{
    code = this->code;
    strcpy(description, this->description);
    cost = this->cost;
    amount = this->amount;
    longitude = this->longitude;
    lattitude = this->lattitude;
}


void Product::print()
{
    cout<< setw(3) << "460" << setw(12) << this->code <<
    setw(15) << this->description <<
    setw(10) << this->cost <<
    setw(10) << this->amount <<
    setw(10) << this->longitude <<
    setw(10) << this->lattitude <<endl;
}

double Product::validate_component(double comp, double min, double max)
{
    if (comp <= min) {return min;}
    else if (comp >= max) {return max;}
    else {return comp;}
}
