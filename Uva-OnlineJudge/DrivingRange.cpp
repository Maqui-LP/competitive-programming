/* 
* name: Driving Range
* link: https://vjudge.net/problem/UVA-11857 
* state: Accepted
* date: 15/11/2020
*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int INF = 1 << 30;

struct Road {
    int c1, c2, cost;
};

bool operator < (const Road a, const Road b) {
        return a.cost < b.cost;
}

struct UFDS {
	vector<int> p, rank; //también pueden usarse arreglos estáticos
	
	UFDS (int size) {
		p.clear(); rank.clear();
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

int kruscal(int v, vector<Road> edge) {
    UFDS ds(v);
    int sets = v, ans = 0;
    sort(edge.begin(), edge.end());
    for (int i=0; i < (int)edge.size(); i++) {
        if (ds.union_set(edge[i].c1, edge[i].c2)) {
            sets--;
            ans = max(ans, edge[i].cost);
        }
    }
    if (sets != 1){
        return INF;
    }

    return ans;
}
int main(){
    int n_cities, n_roads, cityA, cityB, rCost, ans;
    vector<Road> roads;
    while(cin >> n_cities >> n_roads, n_cities || n_roads) {
        roads.clear();
        for(int i=0; i < n_roads; i++) {
            cin >> cityA >> cityB >> rCost;
            roads.push_back(Road{cityA, cityB, rCost});
        }
        ans = kruscal(n_cities, roads);
        if (ans == INF) {
            cout << "IMPOSSIBLE" << endl;
        }
        else {
            cout << ans << endl;
        }    
    }

    return 0;
}