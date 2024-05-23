#include <bits/stdc++.h>
using namespace std;

#define MAX 2123456
typedef long long ll;

ll vet[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    ll k, w;
    cin >> t;
    while(t--) {
        cin >> k >> n;
        if(n <= k) {
            cout << n - 1 << "\n";
        } else {
            for(int i = 0; i < k; i++) vet[i] = i;
            w = k * (k - 1) / 2;
            vet[k] = w;
            for(int i = k + 1; i < n; i++) {
                w += vet[i - 1];
                w -= vet[i - k - 1];
                w += 1000007;
                w %= 1000007;
                vet[i] = w;
            }
            cout << vet[n - 1] << "\n";
        }
    }
    return 0;
}
