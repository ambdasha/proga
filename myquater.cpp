#include "myquater.h"
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
Quaternion::Quaternion(double a, double b, double c, double d) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}
Quaternion::Quaternion(const Quaternion & w) {
	this->a = w.a;
	this->b = w.b;
	this->c = w.c;
	this->d = w.d;
}
Quaternion::~Quaternion(){}

void Quaternion::set_all2(double a, double b, double c, double d) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}
void Quaternion::get_all2(double& a, double& b, double& c, double& d) {
	a= this ->a;
	b= this ->b;
	c= this ->c;
	d= this ->d;
}

void Quaternion::print2() {
	cout << a << " + " << b << "i + " << c << "j + " << d << "k" << endl;
}
double Quaternion::norm() {
	return sqrt(a * a + b * b + c * c + d * d);
}
Quaternion Quaternion::sopr() {
	return Quaternion(a, -b, -c, -d);
}
Quaternion Quaternion::normal() {
	double n = norm();
	if (n == 0) return 0;
	return Quaternion(a / n, b / n, c / n, d / n);
}
Quaternion Quaternion::operator/(double scalar) const {
	return Quaternion(a / scalar, b / scalar, c / scalar, d / scalar);
}
Quaternion Quaternion::inverse() {
	double n = norm();
	if (n == 0) throw runtime_error("Cannot invert a zero quaternion.");

	return sopr() / (n * n);
}
Quaternion Quaternion::operator+(const Quaternion& q) {
	return Quaternion(a + q.a, b + q.b, c + q.c, d + q.d);
}
Quaternion Quaternion::operator-(const Quaternion& q) {
	return Quaternion(a - q.a, b - q.b, c - q.c, d - q.d);
}
Quaternion Quaternion::operator*(const Quaternion& q) {
	return Quaternion(
		a * q.a - b * q.b - c * q.c - d * q.d,
		a * q.b + b * q.a + c * q.d - d * q.c,
		a * q.c - b * q.d + c * q.a + d * q.b,
		a * q.d + b * q.c - c * q.b + d * q.a
	);
}
Quaternion Quaternion::operator/(Quaternion& q) {
	return (*this) * q.inverse();
}
Quaternion Quaternion::operator^(const Quaternion& q) {
	return (a * q.a + b * q.b + c * q.c + d * q.d);
}
double Quaternion::distance(const Quaternion& q1, const Quaternion& q2) {
	return sqrt(pow(q1.a - q2.a, 2) + pow(q1.b - q2.b, 2) +
		pow(q1.c - q2.c, 2) + pow(q1.d - q2.d, 2));
}
double Quaternion::chebyshev(const Quaternion& q1, const Quaternion& q2) {
	double qq = max(fabs(q1.a - q2.a), fabs(q1.b - q2.b));

	return max(qq, max(fabs(q1.c - q2.c), fabs(q1.d - q2.d)));
}