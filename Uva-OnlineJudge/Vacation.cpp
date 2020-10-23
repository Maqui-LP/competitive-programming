/* 
* name: Luggage
* link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1133
* state: Accepted
* date: 23/10/2020
*/

#include <iostream>
#include <string>

using namespace std;

int memo[105][105];

int LCS(string s1, string s2)
{
    int s1_length = s1.length()+1, s2_length = s2.length()+1, i, j;
    
    for ( i = 0; i < s2_length; i++) {
            memo[i][0] = 0;
    }
    for ( j = 0; j < s1_length; j++) {
            memo[0][j] = 0;
    }

    for (i = 1; i < s1_length; i++) {
        for (j = 1; j < s2_length; j++) {
            if (s1[i-1] == s2[j-1]) {
                memo[i][j] = memo[i-1][j-1] + 1;
            } else {
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }

    return memo[s1_length-1][s2_length-1];
}

int main() {
    string s1, s2;
    int TC = 1;
    while (getline(cin, s1), s1[0] != '#') {
        getline(cin, s2);
        cout << "Case #" << TC++ << ": you can visit at most " << LCS(s1, s2) << " cities." << endl;
    }

    return 0;
}