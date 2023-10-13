#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unordered_map<int, int> rooms;
    int q, e, v;
    cin >> q >> e;
    for(int i = 0; i < e; i++) {
        cin >> v;
        rooms[v] = 1;
    }
    for(int j = 0; j < q; j++) {
        cin >> v;
        if(rooms[v] == 0) cout << 1 << "\n";
        else cout << 0 << "\n";
        rooms[v] = 1;
    }
    return 0;
}