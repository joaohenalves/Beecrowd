#include <bits/stdc++.h>
using namespace std;

double calcDist(double x1, double x2, double y1, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double xh, yh, xl, yl, xr, yr, xs, ys, speed, distup, distdown;
    while(cin >> xh >> yh >> xs >> ys >> speed) {
        cin >> xl >> yl >> xr >> yr;
        distup = (calcDist(xh, xl, yh, yr) + (xr - xl) + calcDist(xr, xs, yr, ys)) / speed;
        distdown = (calcDist(xh, xl, yh, yl) + (xr - xl) + calcDist(xr, xs, yl, ys)) / speed;
        cout << fixed;
        cout.precision(1);
        cout << min(distup, distdown) << "\n";
    }
    return 0;
}