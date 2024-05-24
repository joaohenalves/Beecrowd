#include <bits/stdc++.h>
using namespace std;

#define MAX 2123
#define MAX_HULL 4123

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
int np, k;

int cross(vec u, vec v) {
    return (u.x * v.y - u.y * v.x) <= 0;
}

void convexHull() {
    k = 0;
    for(int i = 0; i < np; i++) {
        while(k >= 2 && !cross(vec(hull[k - 2], p[i]), vec(hull[k - 2], hull[k - 1]))) {
            k--;
        }
        hull[k++] = p[i];
    }
    for(int i = np - 2, t = k + 1; i >= 0; i--) {
        while(k >= t && !cross(vec(hull[k - 2], p[i]), vec(hull[k - 2], hull[k - 1]))) {
            k--;
        }
        hull[k++] = p[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y, ans, i;
    while(cin >> n, n) {
        set<point> s;
        ans = 0;
        while(n--) {
            cin >> x >> y;
            s.insert(point(x, y));
        }
        while(!s.empty()) {
            np = 0;
            for(auto &q : s) p[np++] = q;
            convexHull();
            ans++;
            for(i = 0; i < k; i++) s.erase(hull[i]);
        }
        cout << (ans & 1 ? "Take this onion to the lab!" : "Do not take this onion to the lab!") << "\n";
    } 
    return 0;
}
