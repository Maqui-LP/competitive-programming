/* 
* name: Dog And Gopher
* link: https://vjudge.net/problem/UVA-10310
* status: Accepted
* date: 27/11/2020
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

struct coord {
    double x, y;
};

coord gopher, dog, hole, escape_hole;
vector<coord> holes;
bool success;
int n_holes;

double dist(coord a, coord b){
    return hypot(a.x-b.x, a.y - b.y);
}

coord escape(){
    success = false;
    escape_hole.x = 0.0;
    escape_hole.y = 0.0;
    for (int i=0; i < n_holes; i++){
        double gc1, gc2, dc1, dc2;
        gc1 = holes[i].x - gopher.x;
        gc2 = holes[i].y - gopher.y;
        // Cpp reference: "hypot(x, y), hypot(y, x), and hypot(x, -y) are equivalent"
        //El perro es el doble de rapido
        if(hypot(gc1, gc2) <= dist(holes[i], dog) * 0.5){
            success = true;
            escape_hole.x = holes[i].x;
            escape_hole.y = holes[i].y;
            return escape_hole;
        }
    }
    return escape_hole;
}

int main(){
    cout << fixed << setprecision(3);
    while(cin >> n_holes){
        //carga coordenadas de gopher y dog
        cin >> gopher.x >> gopher.y >> dog.x >> dog.y;
        //guardo los agujeros disponibles
        holes.clear();
        for (int i=0; i < n_holes; i++){
            cin >> hole.x >> hole.y;
            holes.push_back(hole);
        }

        escape_hole = escape();
        if (success){
            cout << "The gopher can escape through the hole at (" << escape_hole.x << "," << escape_hole.y << ")." << endl;
            //printf("The gopher can escape through the hole at (%.03lf,%0.3lf).\n", escape_hole.x, escape_hole.y)"
        }
        else{
            cout << "The gopher cannot escape." << endl;
        }
    }

    return 0;
}