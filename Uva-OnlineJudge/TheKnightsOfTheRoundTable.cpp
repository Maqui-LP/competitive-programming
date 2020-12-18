/* 
* name: The Knights Of The Round Table
* link: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1136
* status: Accepted
* date: 15/12/2020
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
double a, b, c, r, s;


/*
* Calculates the area of a triangle a-b-c using Heron's formula
*/
double area() {
    s = (a + b + c)*0.5;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

/*
*  Calculates the radius of a inscribed circle on triangle
*/

double radius() {
    return area()/s;
}

int main() {
    cout << fixed << setprecision(3);
    
    while(cin >> a >> b >> c) {
        if ( a == 0.0 || b == 0.0 || c == 0.0) {
            cout << "The radius of the round table is: 0.000" << endl;
        }
        else {
            r = radius();
            cout << "The radius of the round table is: " << r << endl;
        }
    }

    return 0;
}