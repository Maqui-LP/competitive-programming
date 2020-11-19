/* 
* name: Vertex
* link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=216
* state: Accepted
* date: 12/11/2020
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int N=105;
vector<int> grafo[N];
bool visitado[N];
queue<int> cola;

void bfs(int ini){
    memset(visitado, 0, sizeof(visitado));
    cola.push(ini);
    int t, w;
    while(!cola.empty()){
        t = cola.front();
        cola.pop();
        int size = (int)grafo[t].size();
        for (int i=0; i < size; i++){
            if(!visitado[grafo[t][i]]){
                cola.push(grafo[t][i]);
                visitado[grafo[t][i]] = true;
            }
        }
    }

}

int main() {
    int vertices, inicio, destino, TC, i;
    while(cin >> vertices, vertices != 0){
        for(i = 1; i <= vertices; i++ ){
            grafo[i].clear();
        }
        //Cargo el grafo donde en grafo[inicio] tengo el vector  
        //de vertices con los que se relaciona el vertice inicio
        while(cin >> inicio, inicio != 0){
            while(cin >> destino, destino != 0){
                grafo[inicio].push_back(destino);
            }
                
        }
        cin >> TC;
        while (TC--){
            cin >> inicio;
            bfs(inicio);
            vector<int> no_visitados;
            for (i=1; i <= vertices; i++){
                if (!visitado[i]){
                    no_visitados.push_back(i);
                }
            }
            int tamanio = no_visitados.size();
            cout << tamanio;
            for (i=0; i < tamanio; i++){
                cout << " " << no_visitados[i];
            }
            cout << endl;
        }
    }
    
    return 0;
}