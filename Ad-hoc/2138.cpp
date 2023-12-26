#include <bits/stdc++.h>
using namespace std; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    char c, n;
    int mx = 0, occ[10];
    memset(occ, 0, sizeof(occ));
    while(c = getchar(), c != EOF) {
        if(c == '\n') {
            cout << n << "\n";
            mx = 0;
            n = -1;
            memset(occ, 0, sizeof(occ));
            continue;
        }
        occ[c - '0']++;
        if(occ[c - '0'] > mx) {
            mx = occ[c - '0'];
            n = c;
        } else if(occ[c - '0'] == mx) n = max(n, c);
    }
    return 0;
}
