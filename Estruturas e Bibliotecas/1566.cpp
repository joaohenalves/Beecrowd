#include <bits/stdc++.h>
using namespace std;

#define MAX 239

int c[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m, h;
    cin >> t;
    while(t--) {
        cin >> n;
        m = 0;
        memset(c, 0, sizeof(c));
        for(int i = 0; i < n; i++) {
            cin >> h;
            c[h]++;
        }
        for(int i = 0; i < MAX; i++) {
            while(c[i]) {
                m++;
                cout << i << (m != n ? " " : "\n");
                c[i]--;
            }
        }
    }
    return 0;
}
