#include <bits/stdc++.h>
using namespace std;
 
#define MAX 112345
#define MAX_HULL 212345
 
struct point {
    int x, y;
    point() {}
    point(int _x, int _y) : x(_x), y(_y) {}
};
 
struct vec {
    int x, y;
    vec() {}
    vec(int _x, int _y) : x(_x), y(_y) {}
    vec(point a, point b) : x(b.x - a.x), y(b.y - a.y) {}
};
 
bool operator<(point a, point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
 
point p[MAX], hull[MAX_HULL];
int n;
 
int cross(vec u, vec v) {
    return (u.x * v.y - u.y * v.x) <= 0;
}

double d(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
 
double convexHull() {
    int k = 0;
	double ans = 0;
    sort(p, p + n);
    for(int i = 0; i < n; i++) {
        while(k >= 2 && cross(vec(hull[k - 2], p[i]), vec(hull[k - 2], hull[k - 1]))) {
            k--;
        }
        hull[k++] = p[i];
    }
    for(int i = n - 2, t = k + 1; i >= 0; i--) {
        while(k >= t && cross(vec(hull[k - 2], p[i]), vec(hull[k - 2], hull[k - 1]))) {
            k--;
        }
        hull[k++] = p[i];
    }
	for(int i = 1; i < k; i++) {
		ans += d(hull[i].x, hull[i].y, hull[i - 1].x, hull[i - 1].y);
	}
	return ans;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y, i;
	while(cin >> n, n) {
		for(i = 0; i < n; i++) {
			cin >> x >> y;
			p[i] = point(x, y);
		}
		cout << fixed;
		cout.precision(2);
		cout << "Tera que comprar uma fita de tamanho " << convexHull() << ".\n";
	}
    return 0;
}
