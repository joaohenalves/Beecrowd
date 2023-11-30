#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w, s, c, p, m, g;
    string titans;
    cin >> n >> w >> titans;
    int walls[n + 1];
    int pos[3] = {1, 1, 1};
    for(int i = 0; i < n + 1; i++) walls[i] = w;
    cin >> s; p = s;
    cin >> s; m = s;
    cin >> s; g = s;
    for(int i = 0; i < n; i++) {
        if(titans[i] == 'P') { s = p; c = 0; }
        else if(titans[i] == 'M') { s = m; c = 1; }
        else if(titans[i] == 'G') { s = g; c = 2; }
        while(walls[pos[c]] < s) {
            pos[c]++;
        }
        walls[pos[c]] -= s;
    }
    cout << max(pos[0], max(pos[1], pos[2])) << "\n";
    return 0;
}
