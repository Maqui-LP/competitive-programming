/* 
* name: All Roads Leads Where?
* link: https://vjudge.net/problem/UVA-10009
* state: Accepted
* date: 13/11/2020
*/

#include <iostream>
#include <string>

using namespace std;

#define INF 1e9
#define N 26 //cantidad de letras en el abecedario ingles
int ady[N][N], c[N][N];
string s, t;

void floyd() {
    for(int a = 0; a < N; a++) {
        for(int b=0; b < N; b++) {
            for(int d=0; d < N; d++) {
                if (ady[b][d] > ady[b][a] + ady[a][d]) {
                    ady[b][d] = ady[b][a] + ady[a][d];
                    c[b][d] = c[a][d];
                }
            }
        }
    }

}

//Impresion del camino
void camino(int i, int j) {
    if (i != j) {
        camino(i, c[i][j]);
    }
    cout << (char)(j + 'A');
}

int main() {
    int TC, m, q;
    cin >> TC;
    while(TC--) {
        cin >> m >> q;

        //inicializo la matriz para floyd
        int j;
        for (int i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                ady[i][j] = INF;
                c[i][j] = i;
            }
            ady[i][j] = 0;
        }

        //cargo la matriz
        while(m--) {
            cin >> s >> t;
            ady[s[0]-'A'][t[0]-'A']  = ady[t[0]-'A'][s[0]-'A'] = 1;
        }

        floyd();

        while(q--) {
            cin >> s >> t;
            camino(s[0] - 'A', t[0] - 'A');
            cout << endl;
        }

        if (TC != 0) {
            cout << endl;
        }
    }

    return 0;
}