#pragma once
class Ellipse {
private:

    double h, k, a, b;
    void f();

public:
    Ellipse(double h = 0, double k = 0, double a = 1, double b = 1);
    Ellipse(const Ellipse &e);
    ~Ellipse();

    void set_all1(double h, double k, double a, double b);
    void get_all1(double& h, double& k, double& a, double& b);

    double calculateC();
    void getVershina();
    void getFoc();
    double focHorda();
    double eccentr();
    void print1();
    bool proverka(const double x, const double y);
    double P();
    double area();
    double findY(double x);
    double findX(double y);


};