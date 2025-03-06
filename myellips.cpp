#include "myellips.h"
#include <iostream>
#include <cmath>
using namespace std;
void Ellipse::f() {
    if (a <= b) {
        cout << "Длина большой полуоси должна быть больше длины малой полуоси." << endl;
        cout << "Введите новые значения:" << endl;
        cin >> a >> b;
        f();
    }
}
Ellipse::Ellipse(double h, double k, double a, double b) {
this->h = h;
this->k = k;
this->a = a;
this->b = b;
f();
}
Ellipse::Ellipse(const Ellipse& e) {
    this->h = e.h;
    this->k = e.k;
    this->a = e.a;
    this->b = e.b;
}
Ellipse::~Ellipse() {}

void Ellipse::set_all1(double h, double k, double a, double b) {
    this->h = h;
    this->k = k;
    this->a = a;
    this->b = b;
    f();
}
void Ellipse::get_all1(double& h, double& k, double& a, double& b) {
    h = this->h;
    k = this->k;
    a = this->a;
    b = this->b;
}
double Ellipse::calculateC() {
    return sqrt(a * a - b * b);
}
void Ellipse::getVershina() {
    if (a >= b) {
        cout << "Вершины: (" << h - a << ", " << k << "), (" << h + a << ", " << k << ")" << endl;
    }
    else {
        cout << "Вершины: (" << h << ", " << k - a << "), (" << h << ", " << k + a << ")" << endl;
    }
}
void Ellipse::getFoc() {
    double c = calculateC();
    if (a >= b) {
        cout << "Фокусы: (" << h - c << ", " << k << "), (" << h + c << ", " << k << ")" << endl;
    }
    else {
        cout << "Фокусы: (" << h << ", " << k - c << "), (" << h << ", " << k + c << ")" << endl;
    }
}
double Ellipse::focHorda() {
    return (2 * b * sqrt(1 - (b * b) / (a * a)));
}
double Ellipse::eccentr() {
    return calculateC() / a;
}
void Ellipse::print1() {
    cout << "Уравнение эллипса: ((x - " << h << ")^2 / " << (a * a)
        << ") + ((y - " << k << ")^2 / " << (b * b) << ") = 1" << endl;
    cout << "Центр: (" << h << ", " << k << ")" << endl;
    getVershina();
    getFoc();

}
bool Ellipse::proverka(const double x, const double y) {
    return ((pow(x - h, 2) / (a * a)) + (pow(y - k, 2) / (b * b))) <= 1;
}
double Ellipse::P() {
    return 3.14 * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
}
double Ellipse::area() {
    return 3.14 * a * b;
}
double Ellipse::findY(double x) {
    return k + (b / a) * sqrt(a * a - (x - h) * (x - h));
}
double Ellipse::findX(double y) {
    return h + sqrt(a * a * (1 - (y - k) * (y - k) / (b * b)));
}