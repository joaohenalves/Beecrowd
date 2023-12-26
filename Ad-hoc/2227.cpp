#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v, maxCount, c = 0, flights[112];
    while(cin >> n >> m, n) {
        fill(flights, flights + n + 1, 0);
        maxCount = 0;
        while(m--) {
            cin >> u >> v;
            flights[u]++;
            flights[v]++;
            maxCount = max(maxCount, max(flights[u], flights[v]));
        }
        cout << "Teste " << ++c << "\n";
        for(int i = 1; i <= n; i++) {
            if(flights[i] == maxCount) {
                cout << i << " ";
            }
        }
        cout << "\n\n";
    }
    return 0;
}
