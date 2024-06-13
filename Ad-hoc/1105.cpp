#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

int s[21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int b, n, x, y, z, flag;
    while(cin >> b >> n, b) {
        for(int i = 0; i < b; i++) {
            cin >> s[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            s[x - 1] -= z;
            s[y - 1] += z;
        }
        flag = 1;
        for(int i = 0; i < b; i++) {
            if(s[i] < 0) flag = 0;
        }
        cout << (flag ? 'S' : 'N') << "\n";
    }
    return 0;
}
