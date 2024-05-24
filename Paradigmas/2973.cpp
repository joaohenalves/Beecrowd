#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
#define MAXBIN 1000000000
typedef long long ll;

int n, c, t, bags[MAX];

bool check(ll x) {
    int p = 1;
    ll total = t * x;
    for(int i = 0; i < n; i++) {
        if(bags[i] > t * x || p > c) return false;
        if(total >= bags[i]) total -= bags[i];
        else {
            total = t * x - bags[i];
            p++;
        }
    }
    return p <= c;
}

int binSearch() {
    ll mid, inf = 0, sup = MAXBIN;
    while(inf < sup) {
        mid = inf + (sup - inf) / 2;
        if(check(mid)) sup = mid;
        else inf = mid + 1;
    }
    return inf;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c >> t;
    for(int i = 0; i < n; i++) {
        cin >> bags[i];
    }
    cout << binSearch() << "\n";
    return 0;
}
