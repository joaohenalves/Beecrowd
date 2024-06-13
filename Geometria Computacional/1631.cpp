#include <bits/stdc++.h>
using namespace std;

#define MAX 112

struct point {
    double x, y;
    point() {}
    point(double _x, double _y) : x(_x), y(_y) {}
};
 
struct vec {
    double x, y;
    vec() {}
    vec(double _x, double _y) : x(_x), y(_y) {}
    vec(point a, point b) : x(b.x - a.x), y(b.y - a.y) {}
};
 
point p[MAX];
double line[3];
int n;
 
int cross(vec u, vec v) {
    return (u.x * v.y - u.y * v.x) <= 0;
}

double d(double x1, double y1) {
	double sup = fabs(line[0] * x1 + line[1] * y1 + line[2]);
	return sup / sqrt(line[0] * line[0] + line[1] * line[1]);
}

void calcLine(double x1, double y1, double x2, double y2) {
	if(x1 != x2) {
		double m = (y1 - y2) / (x1 - x2);
		line[0] = -m;
		line[1] = 1;
		line[2] = -m * -x1 - y1;
	} else {
		line[0] = 1;
		line[1] = 0;
		line[2] = -x1;
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	double x, y;
	double dir, esq, total;
	while(cin >> n, n) {
		total = 1e9;
		for(int i = 0; i < n; i++) {
			cin >> x >> y;
			p[i] = point(x, y);
		}
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				vec drt = vec(p[i], p[j]);
				calcLine(p[i].x, p[i].y, p[j].x, p[j].y);
				dir = esq = 0;
				for(int k = 0; k < n; k++) {
					vec temp = vec(p[i], p[k]);
					double z = d(p[k].x, p[k].y);
					if(cross(drt, temp)) {
						dir += z;
					} else {
						esq += z;
					}
				}
				total = min(total, fabs(esq - dir));
			}
		}
		cout << fixed;
		cout.precision(3);
		cout << total << "\n";
	}
    return 0;
}
