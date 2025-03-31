#pragma once


class Polynomial
{
private:
    double *coef_vect;
    int *expo_vect;
    double x;
    int size;

public:
    Polynomial();
    Polynomial(double new_x, int new_size);
    Polynomial(const Polynomial &p);
    ~Polynomial();

    double *get_coef();
    int *get_expo();
    int get_size();
    double get_x();
    void set_coef(double *coef, int size_coef);
    void set_expo();
    void set_size(int new_size);
    void set_x(double new_x);
    void print();

    int get_pow();
};


Polynomial sum(Polynomial &p1, Polynomial &p2);
Polynomial dif(Polynomial &p1, Polynomial &p2);
double val(Polynomial &p);