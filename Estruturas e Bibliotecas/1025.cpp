#include <bits/stdc++.h>
using namespace std;

#define MAX 11234

int num[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q, x, pos, c = 1;
    while(cin >> n >> q, n) {
        for(int i = 0; i < n; i++) {
            cin >> num[i];
        }
        sort(num, num + n);
        cout << "CASE# " << c << ":\n";
        for(int i = 0; i < q; i++) {
            cin >> x;
            pos = lower_bound(num, num + n, x) - num;
            if(pos != n && num[pos] == x) cout << x << " found at " << pos + 1 << "\n";
            else cout << x << " not found\n";
        }
        c++;
    }
    return 0;
}
