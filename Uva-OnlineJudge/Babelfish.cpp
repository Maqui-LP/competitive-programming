#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main(){
    string a, b, line;
    stringstream ss;
    map<string,string> dict;
    while(getline(cin,line), line.length()){
        ss.clear();
        ss << line;
        ss >> a >> b;
        dict[b] = a;
    }
    while(cin >> b){
        if(dict.find(b) == dict.end()){
            cout << "eh" << endl;
        }
        else {
            cout << dict[b] << endl;
        }
    }
    return 0;
}