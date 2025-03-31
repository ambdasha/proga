#include <iostream>
#include <iomanip>
#include "polynomial.h"
#include "vect_polynomial.h"


using namespace std;

VectPolynomial::VectPolynomial()
{
    this->size = 0;
    this->status_size = 0;
    this->list = nullptr;
}

VectPolynomial::VectPolynomial(int new_size)
{
    this->size = new_size;
    this->status_size = 0;
    this->list = new Polynomial[new_size];
}

VectPolynomial::VectPolynomial(const VectPolynomial &v)
{
    this->size = v.size;
    this->status_size = v.status_size;
    this->list = v.list;
}

VectPolynomial::~VectPolynomial(){}


Polynomial *VectPolynomial::get_list()
{
    return this->list;
}

int VectPolynomial::get_size()
{
    return this->size;
}

int VectPolynomial::get_status_size()
{
    return this->status_size;
}

void VectPolynomial::print()
{
    cout << "This vector have: " << endl;
    for (int i = 0; i < this->status_size; i++)
    {
        cout << i + 1 << ": ";
        this->list[i].print();
    }
}

void VectPolynomial::set_polymial(Polynomial &p, int id)
{
    this->list[id].set_size(p.get_size());
    this->list[id].set_coef(p.get_coef(), p.get_size());
    this->list[id].set_x(p.get_x());
    this->status_size += 1;
}

void VectPolynomial::set_list(Polynomial *new_list, int size_list)
{
    if (this->size > size_list)
    {
        for (int i = 0; i < size_list; i++)
        {
            this->list[i] = new_list[i];
            this->status_size += 1;
        }
    }
    else
    {
        cout << "Sorry, new size more size of vector:<!" << endl;
    }
}

void VectPolynomial::set_size(int new_size)
{
    if (new_size == this->size)
    {
        cout << "U don't change size!"<< endl;
    }
    else
    {
        Polynomial *a = new Polynomial[new_size];
        if (new_size > this->size)
        {
            for (int i = 0; i < this->size; i++)
            {
                a[i] = this->list[i];
            }
            this->status_size += new_size - this->size;
        }
        else
        {
            for (int i = 0; i < new_size; i++)
            {
                a[i] = this->list[i];
            }
            
        this->list = a;
        this->size = new_size;
        this->status_size = (this->status_size >= this->size ? this->size : this->status_size);
        }
    }   
}


int freePolinomail(VectPolynomial &v)
{
    return v.get_size() - v.get_status_size();
}
