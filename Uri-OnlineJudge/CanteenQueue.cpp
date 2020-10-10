/* 
* name: Canteen Queue
* link: https://www.urionlinejudge.com.br/judge/en/problems/view/1548
* state: Accepted
* date: 07/10/2020
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int cant, num, ord;
    cin >> cant;
    while (cant --){
        cin >> num;
        int original [num];
        int sorted [num];
        for (int i=0; i < num; i++){
            cin >> original[i];
            sorted[i]=original[i];
        }
        sort(sorted, sorted+num, greater<int>());
        ord = 0;
        for(int j=0; j< num; j++){
            if(sorted[j]==original[j]){
                ord++;
            }
        }
        cout << ord << endl;
    }
    return 0;
}