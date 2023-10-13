#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, temp, maxApp;
    vector<int> playersAtt;
    vector<int> playersDef;
    for(;;) {
        cin >> n >> m;
        if(n == 0) break;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            playersAtt.emplace_back(temp);
        }
        for(int j = 0; j < m; j++) {
            cin >> temp;
            playersDef.emplace_back(temp);
        }
        sort(playersAtt.begin(), playersAtt.end());
        sort(playersDef.begin(), playersDef.end());
        if(playersAtt[0] >= playersDef[1]) {
            cout << "N\n";
        } else cout << "Y\n";
        playersAtt.clear();
        playersDef.clear();
    }
    return 0;
}