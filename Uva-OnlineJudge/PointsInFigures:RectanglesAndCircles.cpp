/* 
* name: Points in Figures: Rectangles and Circles 
* link:https://vjudge.net/problem/UVA-477
* status: Accepted
* date: 27/11/2020
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>


#define EPS 1e-9

using namespace std;

struct coord {
    double x, y;
    coord () {
        x = y = 0;
    }
    coord(double _x, double _y) : x(_x), y(_y) {

    };
};
struct figure {
    vector<coord> points;
    double r;
    char t;

    figure(char type, coord upp_left, coord low_right) {
        t = type;
        points.push_back(coord(upp_left.x, upp_left.y));
        points.push_back(coord(upp_left.x, low_right.y));
        points.push_back(coord(low_right.x, upp_left.y));
        points.push_back(coord(low_right.x, low_right.y));
    }
    figure(char type, coord center, double radius) {
        t = type;
        r = radius;
        points.push_back(center);
    }
};

coord upper_left, lower_right, center;
vector<figure> figures;
double radius;
char type;
coord limit = coord(9999.9, 9999.9);

bool operator == (const coord p1, const coord p2) {
    return ((fabs(p1.x - p2.x) < EPS) && (fabs(p1.y - p2.y) < EPS));
}
double distance(coord a, coord b) {
    return hypot(a.x - b.x, a.y - b.y);
}
bool between(double a, double b, double c) {
    return (b < a && a < c);
}
bool inside_circle(figure f, coord p) {
    bool inside = false;
    if (distance(p, f.points[0]) < f.r) {
        inside = true;
    }
    return inside;
}
bool inside_rectangle(figure f, coord p) {
    return (between(p.x, f.points[0].x, f.points[3].x) && between(p.y, f.points[3].y, f.points[0].y));
}
bool is_inside(figure f, coord p) {
    if(f.t == 'r'){
        return inside_rectangle(f, p);
    }
    else {
        return inside_circle(f, p);
    }
}


int main() {
    figures.clear();
    int n_figures=0;
    while(cin >> type, type != '*') {
        if (type == 'r') {
            cin >> upper_left.x >> upper_left.y >> lower_right.x >> lower_right.y;
            figures.push_back(figure(type, upper_left, lower_right));
        }
        else {
            cin >> center.x >> center.y >> radius;
            figures.push_back(figure(type, center, radius));
        }
        n_figures++;
    }
    int point_n = 1;
    coord point;
    while(cin >> point.x >> point.y, !(point == limit)) {
        bool inside = false;
        for(int i=0; i < n_figures; i++) {
            if(is_inside(figures[i], point)){
                cout << "Point "<< point_n << " is contained in figure " << i+1 << endl; 
                inside = true;
            }
        }
        if (!inside) {
            cout << "Point "<< point_n << " is not contained in any figure" << endl;
        }
        point_n++;
    }

    return 0;
}