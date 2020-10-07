#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

std::vector<std::string> split(std::string strToSplit, char delimeter)
{
    stringstream ss(strToSplit);
    string item;
    vector<string> splittedStrings;
    while (getline(ss, item, delimeter))
    {
       splittedStrings.push_back(item);
    }
    return splittedStrings;
}

int main(){
    vector<string> splittedString;
    string line, var;
    map<char, double> dict;
    int cant;
    double sum;
    char delimeter = '/';
    dict['W'] = 1.0;
    dict['H'] = 0.5;
    dict['Q'] = 0.25;
    dict['E'] = 0.125;
    dict['S'] = 0.0625;
    dict['T'] = 0.03125;
    dict['X'] = 0.015625;
    while (getline(cin,line) , line.length()){
        if( line == "*"){
            break;
        }
        splittedString = split(line, delimeter);
        cant = 0;
        for(int i = 0; i < (int)splittedString.size(); i++ ){
            sum = 0;
            var = splittedString[i];
            for(int j = 0; j < (int)var.length(); j++){
                char letter = var[j];
                if(dict.find(letter) != dict.end()){
                    sum = sum + dict[letter];
                }
            }
            if (sum == 1.0 ){
                cant++;
            }
        }
        cout << cant << endl; 
    }
    return 0;
}