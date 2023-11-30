#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w, s, c;
    string titans;
    unordered_map<char, int> sz;
    unordered_map<char, int> id;
    cin >> n >> w >> titans;
    int walls[n + 1];
    int pos[3] = {1, 1, 1};
    for(int i = 0; i < n + 1; i++) walls[i] = w;
    cin >> s; sz['P'] = s; id['P'] = 0;
    cin >> s; sz['M'] = s; id['M'] = 1;
    cin >> s; sz['G'] = s; id['G'] = 2;
    for(int i = 0; i < n; i++) {
        c = id[titans[i]];
        while(walls[pos[id[titans[i]]]] < sz[titans[i]]) {
            pos[id[titans[i]]]++;
        }
        walls[pos[id[titans[i]]]] -= sz[titans[i]];
    }
    cout << max(pos[0], max(pos[1], pos[2])) << "\n";
    return 0;
}
