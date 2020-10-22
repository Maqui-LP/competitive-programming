/* 
* name: EDIST - Edit distance
* link: https://www.spoj.com/problems/EDIST/
* state: Accepted
* date: 19/10/2020
*/

#include <iostream>
#include <string>
using namespace std;

int DP[2005][2005];

int ED(string s, string t) {
    int n = s.length() + 1, m = t.length() + 1;
    int i, j;

    for (i = 0; i < n; i++){
        DP[i][0] = i;
    } 
    for (j = 0; j < m; j++){
        DP[0][j] = j;
    } 
        
    for (i = 1; i < n; i++){
        for (j = 1; j < m; j++){
            DP[i][j] = (s[i-1] == t[j-1]) ? DP[i-1][j-1] : (1 + min(min(DP[i-1][j], DP[i][j-1]), DP[i-1][j-1]));
        }
    }

    return DP[n-1][m-1];
}

int main(int argc, char const *argv[]) {

    int t;
    string str1, str2;

    cin >> t;
    cin.ignore();
    while(t--){
        cin >> str1 >> str2;
        cout << ED(str1, str2) << endl;
    }

    return 0;
}