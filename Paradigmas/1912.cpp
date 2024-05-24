#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
typedef long long ll;

int n, h[MAX], pref[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll total, target, cut;
    double ans;
    while(cin >> n >> target, n) {
        total = 0;
        for(int i = 0; i < n; i++) {
            cin >> h[i];
            total += h[i];
        }
        if(total == target) cout << ":D\n";
        else if(total < target) cout << "-.-\n";
        else if(n == 1) cout << h[0] - target << "\n";
        else {
            sort(h, h + n);
            pref[0] = 0;
            for(int i = 0; i < n; i++) {
                pref[i + 1] = pref[i] + h[i];
            }
            for(int i = n - 1; i >= 0; i--) {
                cut = (pref[n] - pref[i]) - (h[i - 1] * (n - i));
                if(cut >= target) {
                    ans = h[i - 1] + ((double)(cut - target) / (double)(n - i));
                    break;
                }
            }
            cout << fixed;
            cout.precision(4);
            cout << ans << "\n";
        }
    }
    return 0;
}
