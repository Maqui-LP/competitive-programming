//Not working in cases like 4 1 4 3 5
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int past, current, diff, num;
    string output;
    bool jolly = true;
    while(cin >> num){
        diff = num - 1;
        cant = num;
        past = 3005;
        for (int i=0; i < num; i++){
            cin >> current;
            if((past != 3005) and abs(current - past) != diff){
                jolly=false;
            }
            diff--;
            past=current;
        }
        output = !jolly ? "Not Jolly" : "Jolly";
        cout << output << endl;
        jolly=true;
    }
    return 0;
}