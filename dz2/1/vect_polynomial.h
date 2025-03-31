#pragma once
#include "polynomial.h"


class VectPolynomial
{
private:
    Polynomial *list;
    int size;
    int status_size;

public:
    VectPolynomial();
    VectPolynomial(int size);
    VectPolynomial(const VectPolynomial &v);
    ~VectPolynomial();

    Polynomial *get_list();
    int get_size();
    int get_status_size();
    void print();
    void set_polymial(Polynomial &p, int id);
    void set_list(Polynomial *new_list, int size_list);
    void set_size(int new_size);
};


int freePolinomail(VectPolynomial &v);
