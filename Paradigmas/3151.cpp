#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> dd;

bool comp(dd a, dd b) {
    return a.first > b.first;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<double, double> > items(112);
    int t, n, w;
    double ans;
    cin >> t;
    while(t--) {
        cin >> n >> w;
        for(int i = 0; i < n; i++) {
            cin >> items[i].first >> items[i].second;
            items[i].first = items[i].first / items[i].second;
        }
        sort(items.begin(), items.begin() + n, comp);
        ans = 0;
        for(int i = 0; i < n; i++) {
            if(items[i].second <= w) {
                ans += items[i].second * items[i].first;
                w -= items[i].second;
            } else {
                ans += w * items[i].first;
                break;
            }
        }
        cout << fixed;
        cout.precision(2);
        cout << ans << "\n";
    }
    return 0;
}
