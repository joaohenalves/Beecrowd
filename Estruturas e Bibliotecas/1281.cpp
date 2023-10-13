#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str1;
    float val, total = 0;
    int n, m, i, j, k;
    cout << fixed;
    cout.precision(2);
    cin >> n;
    for(i = 0; i < n; ++i) {
        unordered_map<string, float> prices;
        cin >> m;
        for(j = 0; j < m; ++j) {
            cin >> str1 >> val;
            prices[str1] = val;
        }
        cin >> m;
        for(k = 0; k < m; ++k) {
            cin >> str1 >> val;
            total += val * prices[str1];
        }
        cout << "R$ " << total << "\n";
        total = 0;
    }
    return 0;
}