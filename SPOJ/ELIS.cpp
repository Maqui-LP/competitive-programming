/* 
* name: ELIS - Easy Longest Increasing Subsequence
* link: https://www.spoj.com/problems/ELIS/
* state: Accepted
* date: 20/10/2020
*/

#include <iostream>
#include <vector>

using namespace std;

int DP[11]; int n;

int lis(int* seq){
    int ans = 0;
    for (int i=0; i < n; i++) {
        DP[i] = 1; // Mínimo LIS = 1
        for (int j=0; j < i; j++) {
            if ((seq[j] < seq[i]) && DP[i] < DP[j] + 1) {
                DP[i] = DP[j] + 1;
            }
        }
        if (DP[ans] < DP[i]){
            ans = i;
        }
    }
    return ans; 
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int inputs[11];
    cin >> n;
    for (int i = 0; i < n; i++) {
            cin >> inputs[i];
    }

    cout << DP[lis(inputs)] << endl;

    return 0;
}