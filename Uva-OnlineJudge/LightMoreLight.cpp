/* 
* name: Light, more light
* link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1051
* status: Accepted
* date: 10/12/2020
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long n, s, m ;
    while ( cin >> n, n) {
        s = (int) sqrt((double)n);
        m = s * s;
        m == n ? cout << "yes" << endl : cout << "no" << endl ;
    }

    return 0;
}