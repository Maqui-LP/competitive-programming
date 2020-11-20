/* 
* name: ACM Contest And Blackout
* link: https://vjudge.net/problem/UVA-10600
* state: Wrong Answer
* date: 15/11/2020
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int INF = 1 << 30;


struct UFDS {
	vector<int> p, rank; //también pueden usarse arreglos estáticos
    int sets;
	
	UFDS (int size) {
		p.clear(); rank.clear();
        //sets = size;
		for (int i=0; i < size; i++) {
			p.push_back(i);
			rank.push_back(0);
		}
	}
	
	int find_set (int i) {
		return (i == p[i]) ? i : (p[i] = find_set(p[i]));
	}
	bool same_set (int i, int j) {
		return find_set(i) == find_set(j);
	}
	bool union_set (int i, int j) {
        /*int x = find_set(i);
		int y = find_set(j);
        if(same_set(x, y)){
            return false;
        }
        if(rank[x] < rank[y]){
            p[x]=y;

        } else if(rank[x] > rank[y]) {
				p[y] = x;
            }
            else{
                p[y]=x;
                rank[x]++;
            }
        sets--;

        return true;
    */
        if (!same_set(i, j)) {
			int x = find_set(i);
			int y = find_set(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
			} else {
				p[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
			}
            return true;
		}
        return false;
	}
};

struct Conexion {
    int eA, eB, c;
};

//Esto es para que me lo ordene con el criterio que yo quiero
bool operator < (const Conexion a, const Conexion b)
{
        return a.c < b.c;
}

vector<Conexion> Kruskal(int V, vector<Conexion> aristas){
    vector<Conexion> MST;
    UFDS ds(V);
    int sets = V;
    sort(aristas.begin(), aristas.end());
    for(int i = 0; i < (int)aristas.size(); i++) {
        if (ds.union_set(aristas[i].eA, aristas[i].eB)) {
            MST.push_back(aristas[i]);
        }
    }

    return MST;
}

int Kruskal2(int V, vector<Conexion> aristas, int escA, int escB){
    UFDS ds(V);
    int total=0;
    int sets=V;

    for(int i=0; i < (int)aristas.size(); i++){
        if(aristas[i].eA == escA && aristas[i].eB == escB){
            continue;
        }
        if(ds.union_set(aristas[i].eA, aristas[i].eB)){
            total+=aristas[i].c;
            sets--;
        }
    }
    if(sets != 1) {
        return INF;
    }

    return total;
}

int main(){
    int TC, escuelaA, escuelaB, costo, escuelas, num_conexiones, suma1, suma2, tamanio;
    vector<Conexion> conexiones;
    vector<Conexion> MST;

    cin >> TC;
    while(TC--){
        cin >> escuelas >> num_conexiones;
        conexiones.clear();
        MST.clear();
        //incializo las conexiones. escuelas + conexiones = grafo
        while(num_conexiones--){
            cin >> escuelaA >> escuelaB >> costo;
            conexiones.push_back(Conexion{--escuelaA, --escuelaB, costo});
        }
       
        MST = Kruskal(escuelas, conexiones);
        tamanio = (int) MST.size();
        //suma1 = sumo las aristas de MST (es el minimo peso total)
        suma1 = 0;
        for (int i=0; i < tamanio; i++){
            suma1+=MST[i].c;
        }
        suma2 = INF;
        
        //Para cada una de las aristas del MST: segundo kruskal
        for (int i=0; i < tamanio; i++){
            suma2 = min(suma2, Kruskal2(escuelas, conexiones, MST[i].eA, MST[i].eB));
        }

        if (suma2==INF){
            suma2=suma1;
        }
        cout << suma1 << " " << suma2 << endl;;
    }

    return 0;
}