#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, n, counter;
    double bx, by, x, y, minDist;
    cin >> c;
    for(int i = 0; i < c; i++) {
        cin >> n;
        cin >> bx >> by;
        counter = 1;
        cin >> x >> y;
        minDist = floor(sqrt(pow(x - bx, 2) + pow(y - by, 2)) * 100);
        for(int j = 1; j < n; j++) {
            cin >> x >> y;
            if(floor(sqrt(pow(x - bx, 2) + pow(y - by, 2)) * 100) < minDist) {
                minDist = floor(sqrt(pow(x - bx, 2) + pow(y - by, 2)) * 100);
                counter = j + 1;
            }
        }
        cout << counter << "\n";
    }
    return 0;
}