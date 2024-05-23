#include <bits/stdc++.h>
using namespace std;

#define MAX 1123456
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int, int> iiii;

int n, m;
unordered_map<ll, ii> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    ll x, y, z, mx = INT_MAX;
    for(ll i = 0; i <= 215; i++) {
        x = i * i * i * i;
        for(ll j = i; j <= 215; j++) {
            y = j * j * j * j;
            if(x + y > mx) break;
            v[x + y] = make_pair(i, j);
        }
    }
    cin >> q;
    while(q--) {
        set<vector<int>> ans;
        cin >> z;
        for(auto &[x, y] : v) {
            if(z - x >= 0 && v.find(z - x) != v.end()) {
                vector<int> aux = {y.first, y.second, v[z - x].first, v[z - x].second};
                sort(aux.begin(), aux.end());
                ans.insert(aux);
            }
        }
        cout << ans.size() << "\n";
        for(auto a : ans) {
            for(int i = 0; i < 4; i++) {
                cout << a[i] << (i != 3 ? " " : "\n");
            }
        }
    }
    return 0;
}
