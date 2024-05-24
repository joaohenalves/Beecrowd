#include <bits/stdc++.h>
using namespace std;

int rad[1123456], pos[1123456];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, k, l, maxPos, limit;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        memset(rad, 0, sizeof(rad));
        maxPos = 0;
        for(int i = 0; i < n; i++) {
            cin >> pos[i];
            maxPos = max(maxPos, pos[i]);
        }
        for(int j = 0; j < n; j++) {
            cin >> l;
            rad[pos[j]] = max(rad[pos[j]], l);
        }
        for(int i = 1; i <= maxPos; i++) {
            rad[i] = max(rad[i - 1], rad[i] + (i - k >= 0 ? rad[i - k] : 0));
        }
        cout << rad[maxPos] << "\n";
    }
    return 0;
}
