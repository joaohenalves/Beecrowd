#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second > b.second;
    else return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, temp, maxApp;
    map<int, int> players;
    vector<pair<int, int> > plr;
    for(;;) {
        cin >> n >> m;
        if(n == 0) break;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> temp;
                players[temp]++;
            }
        }
        for(auto p : players) {
            plr.emplace_back(make_pair(p.second, p.first));
        }
        sort(plr.begin(), plr.end(), compare);
        maxApp = plr[plr.size() - 1].first;
        for(int l = plr.size() - 1; l >= 0; l--) {
            if(plr[l].first == maxApp) {
                plr.pop_back();
            } else break;
        }
        cout << plr[plr.size() - 1].second << " ";
        for(int k = plr.size() - 2; k >= 0; k--) {
            if(plr[k].first == plr[plr.size() - 1].first) {
                cout << plr[k].second << " ";
            } else break;
        }
        cout << "\n";
        players.clear();
        plr.clear();
    }
    return 0;
}