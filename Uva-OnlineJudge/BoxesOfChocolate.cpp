/* 
* name: Boxes of Chocolates
* link: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1430
* status: Accepted
* date: 10/12/2020
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int tc, nof, b, k, aux;

    cin >> tc;
    while (tc--) {
        cin >> nof >> b;
        int sum = 0;
        while(b--) {
            cin >> k;
            vector<int> sb(k);
            int j = 0;
            for(int j=0; j < k; j ++) {
                cin >> aux;
                sb[j] = aux % nof;
            }
            int m = 1;
            for(int i=0; i < k; i++) {
                m = (m * sb[i]) % nof;
            }
            sum+=m%nof;
        }
        cout << sum%nof << endl;
    }

    return 0;
}