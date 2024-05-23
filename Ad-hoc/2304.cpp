#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, z, j1, j2, j3;
    char a, b, c;
    cin >> n >> m;
    j1 = j2 = j3 = n;
    for(int i = 0; i < m; i++) {
        cin >> a;
        if(a == 'C') {
            cin >> b >> z;
            if(b == 'D') j1 -= z;
            if(b == 'E') j2 -= z;
            if(b == 'F') j3 -= z;
        }
        if(a == 'V') {
            cin >> b >> z;
            if(b == 'D') j1 += z;
            if(b == 'E') j2 += z;
            if(b == 'F') j3 += z;
        }
        if(a == 'A') {
            cin >> b >> c >> z;
            if(b == 'D') j1 += z;
            if(b == 'E') j2 += z;
            if(b == 'F') j3 += z;
            if(c == 'D') j1 -= z;
            if(c == 'E') j2 -= z;
            if(c == 'F') j3 -= z;
        }
    }
    cout << j1 << " " << j2 << " " << j3 << "\n";
    return 0;
}
