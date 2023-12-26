#include <bits/stdc++.h>
using namespace std;

int rad[1000001], pos[1000001];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, k, l, maxPos, limit;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        maxPos = 0;
        for(int i = 0; i < n; i++) {
            cin >> pos[i];
            maxPos = max(maxPos, pos[i]);
        }
        memset(rad, 0, sizeof(rad));
        for(int j = 0; j < n; j++) {
            cin >> l;
            rad[pos[j]] = max(rad[pos[j]], l);
        }
        for(int i = maxPos; i >= 0; i--) {
            limit = min(1000001, i + k);
            rad[i] = max(rad[i + 1], rad[i] + rad[limit]);
        }
        cout << rad[0] << "\n";
    }
    return 0;
}
