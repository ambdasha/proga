#pragma once
class Quaternion {
private:
    double a, b, c, d;
public:
    Quaternion(double a=1, double b=0, double c=0, double d=0);
    Quaternion(const Quaternion &w);
    ~Quaternion();

    void set_all2(double a, double b, double c, double d);
    void get_all2(double &a, double &b, double &c, double &d);

    void print2();
    double norm();
    Quaternion sopr();
    Quaternion normal();
    Quaternion inverse();
    Quaternion operator/(double scalar) const;
    Quaternion operator+(const Quaternion& q);
    Quaternion operator-(const Quaternion& q);
    Quaternion operator*(const Quaternion& q);
    Quaternion operator/(Quaternion& q);
    Quaternion operator^(const Quaternion& q);
    static double distance(const Quaternion& q1, const Quaternion& q2);
    static double chebyshev(const Quaternion& q1, const Quaternion& q2);
};