/* 
* name: Graph Connectivity
* link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400
* state: Accepted
* date: 2/11/2020
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;
const int M = 30;
bool adj[M][M];
vector<bool> visitado;
int n;

int dfs(int v)
{
        visitado[v] = true;
        int k, respuesta = 1;
        for (k = 0; k < n; k++) {
                if (adj[v][k] && !visitado[k]) {
                        respuesta += dfs(k);
                }
        }

        return respuesta;
}

int main(){
    int TC, respuesta;
    string line;
    cin >> TC;
    getline(cin, line);
    getline(cin, line);
    while(TC--){
        getline(cin, line);
        n =  line[0] - 'A' + 1; //Conversión de letra a número
        memset(adj, 0, sizeof adj); //Reservo memoria. podria ser adj.size()? 
                                   //NO, es igual que el de C, una porcion de memoria, asi que no lo entiende 
        respuesta = 0;
        while (getline(cin, line), line.length()) {
            adj[line[0] - 'A'][line[1] - 'A'] = adj[line[1] - 'A'][line[0] - 'A'] = true;
        }
        visitado.clear();
        for(int j=0; j < n ; j ++){
            visitado.push_back(false);
        }
        //si fuese estatico de 30, podria hacer memset(visitado, 0, sizeof visitado);
        for (int i = 0; i < n; i++) {
            if (!visitado[i]) {
                dfs(i);
                respuesta++;
            }
        }
        cout << respuesta << endl;
        if (TC) {
            cout << endl;
        }

    }

    return 0;
}