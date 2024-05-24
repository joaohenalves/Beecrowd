#include <bits/stdc++.h>
using namespace std;

#define MAX 20
#define MAX_HULL 20

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
map<point, int> pIndex;
set<int> ans;
int n, k;

int cross(vec u, vec v) {
    return (u.x * v.y - u.y * v.x) < 0;
}

void convexHull() {
    k = 0;
    sort(p, p + n);
    for(int i = 0; i < n; i++) {
        while(k >= 2 && !cross(vec(hull[k - 2], p[i]), vec(hull[k - 2], hull[k - 1]))) {
            k--;
        }
        hull[k++] = p[i];
    }
    for(int i = n - 2, t = k + 1; i >= 0; i--) {
        while(k >= t && !cross(vec(hull[k - 2], p[i]), vec(hull[k - 2], hull[k - 1]))) {
            k--;
        }
        hull[k++] = p[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y, i, flag = 0;
    set<int> check;
    n = 5;
    for(i = 0; i < n; i++) {
        cin >> x >> y;
        p[i] = point(x, y);
        pIndex[p[i]] = i;
    }
    convexHull();
    for(i = 0; i < k; i++) {
        check.insert(pIndex[hull[i]]);
        if(pIndex[hull[i]] == 4) flag = 1;
    }
    cout << (flag || check.size() == 2 ? " O>\n<| \n/ >\n" : "\\O/\n | \n/ \\\n");
    return 0;
}
