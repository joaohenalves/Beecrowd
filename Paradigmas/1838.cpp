#include <bits/stdc++.h>
using namespace std;

#define MAX 1134
typedef pair<int, int> ii;

int n, memo[4000];
ii l[MAX];

bool comp(ii a, ii b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int dp(int time, int idx) {
    if(idx >= n) return 0;
    if(memo[time] != -1) return memo[time];
    int aux = 0;
    if(time <= l[idx].first) aux = dp(l[idx].second, idx + 1) + (l[idx].second - l[idx].first);
    return memo[time] = max(aux, dp(time, idx + 1));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int last = 0, total = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> l[i].first >> l[i].second;
    }
    sort(l, l + n, comp);
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0) << "\n";
    return 0;
}
