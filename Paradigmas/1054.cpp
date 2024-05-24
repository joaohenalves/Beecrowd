#include <bits/stdc++.h>
using namespace std;

#define MAX 112

typedef pair<int, int> ii;

vector<ii> stones(MAX);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, p, d, mx;
    string s;
    cin >> t;
    for(int c = 1; c <= t; c++) {
        cin >> p >> d;
        for(int i = 1; i <= p; i++) {
            cin >> s;
            if(s[0] == 'S') {
                stones[i].first = 1;
            } else stones[i].first = 0;
            stones[i].second = stoi(s.substr(2));
        }
        stones[p + 1].second = d;
        stones[p + 1].first = 0;
        mx = 0;
        for(int i = 0; i <= p; i++) {
            if(stones[i + 1].first == 0) {
                mx = max(mx, stones[i + 1].second - stones[i].second);
            } else {
                mx = max(mx, stones[i + 2].second - stones[i].second);
                stones[i + 2].first++;
                i++;
            }
        }
        for(int i = p + 1; i >= 1; i--) {
            if(stones[i - 1].first == 2) {
                mx = max(mx, stones[i].second - stones[i - 2].second);
                i--;
            } else {
                mx = max(mx, stones[i].second - stones[i - 1].second);
            }
        }
        cout << "Case " << c << ": " << mx << "\n";
    }
    return 0;
}
