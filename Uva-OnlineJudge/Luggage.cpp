/* 
* name: Luggage
* link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1605
* status: Accepted
* date: 20/10/2020
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

int N, K;
int DP[25][105];
int sum;

/*
* Splits a string using a character as delimiter  
*
* @param strToSplit is the string to be splitted
* @param delimiter is the character used as delimiter
* @returns splittedStrings vector of string 
*/
vector<string> split(string strToSplit, char delimiter)
{
    stringstream ss(strToSplit);
    string item;
    vector<string> splittedStrings;
    while (getline(ss, item, delimiter))
    {
       splittedStrings.push_back(item);
    }
    return splittedStrings;
}

int mochila (int N, int K, vector<int> elem) { 
    for (int i=0; i<=N; i++){
        DP[i][0] = 1;
    } 
    for (int j=0; j<=K; j++){
        DP[0][j] = 0;
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=K; j++) {
            if (elem[i-1] > j){
                DP[i][j] = DP[i-1][j];
            } 
            else{
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-elem[i-1]]);
            } 
        }
    }
    return DP[N-1][K-1];
 }

int main(int argc, char const *argv[]) {
    int TC;
    string str;
    cin >> TC;
    cin.ignore();
    while (TC--){
        sum=0;
        getline(cin, str);
        vector<string> vec_str = split(str, ' ');
        vector<int> vec_ent;
        for (int i=0; i < (int)vec_str.size(); i++){
            vec_ent.push_back(stoi(vec_str[i]));
            sum = sum + vec_ent[i];
        }
        if ( sum % 2 != 0){
            cout << "NO"<< endl;
        }
        else{
            sum = sum / 2;
            memset(DP, -1, sizeof(DP));
            int ans = mochila(vec_ent.size()+1, sum+1, vec_ent);
            if(ans){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}