/*
* name: Jingle Composing
* link: https://www.urionlinejudge.com.br/judge/en/problems/view/1430
* status: Accepted
* date: 07/10/2020
*/

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;
/*
* Splits a string using a character as delimiter  
*
* @param strToSplit is the string to be splitted
* @param delimiter is the character used as delimiter
* @returns splittedStrings vector of string 
*/
std::vector<std::string> split(std::string strToSplit, char delimiter)
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

int main(){
    vector<string> splittedString;
    string line, measure;
    map<char, double> notes;
    int cant;
    double sum;
    char delimiter = '/';
    notes['W'] = 1.0;
    notes['H'] = 0.5;
    notes['Q'] = 0.25;
    notes['E'] = 0.125;
    notes['S'] = 0.0625;
    notes['T'] = 0.03125;
    notes['X'] = 0.015625;
    while (getline(cin,line) , line.length()){
        if( line == "*"){
            break;
        }
        splittedString = split(line, delimiter);
        cant = 0;
        for(int i = 0; i < (int)splittedString.size(); i++ ){
            sum = 0;
            measure = splittedString[i];
            for(int j = 0; j < (int)measure.length(); j++){
                char letter = measure[j];
                if(notes.find(letter) != notes.end()){
                    sum = sum + notes[letter];
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