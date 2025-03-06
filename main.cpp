#include "myellips.h"
#include "myquater.h"
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    Ellipse q(0, 0, 10, 5);
    q.print1();
    cout << "гиперпараметр с " << q.calculateC() << endl;
    cout << "периметр=" << q.P() << endl << "площадь=" << q.area();
    cout << "эксцентриситет= " << q.eccentr() << endl;
    cout << "при х=3, у=" << q.findY(3) << endl;
    cout << "при y=2, x=" << q.findX(2) << endl;

    Quaternion x(2, 4, 7, 5);
    x.print2();
    Quaternion e(8, 6, 9, 3);
    e.print2();
    (x + e).print2();
    (x - e).print2();

    (x * e).print2();

    (x / e).print2();

    (x ^ e).print2();

}