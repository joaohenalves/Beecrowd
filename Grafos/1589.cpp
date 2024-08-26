#include <bits/stdc++.h>
using namespace std;
 
#define MAX 1123456
#define MAXG 1123
#define MOD 1000000007
#define INF 1123456789
#define INFLL 1123456789123456789
#define EPS 1e-10
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
 
int n, m, arr[MAX];

void multmat(ll a[26][26], ll b[26][26], ll c[26][26], int ord) {
    for(int i = 0; i < ord; i++) {
        for(int j = 0; j < ord; j++) {
            c[i][j] = 0;
            for(int k = 0; k < ord; k++) {
                c[i][j] += (a[i][k] * b[k][j]) % MOD;
                c[i][j] %= MOD;
            }
        }
    }
}

void ident(ll a[26][26], int ord) {
    for(int i = 0; i < ord; i++) {
        for(int j = 0; j < ord; j++) {
            a[i][j] = i == j;
        }
    }
}

void expbin(ll a[26][26], ll b[26][26], ll k, int ord) {
    ll c[26][26];
    if(k < 0) return;
    if(k == 0) ident(b, ord);
    else if(k & 1) {
        expbin(a, c, k - 1, ord);
        multmat(a, c, b, ord);
    } else {
        expbin(a, c, k >> 1, ord);
        multmat(c, c, b, ord);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int col1, row1, col2, row2;
    ll k, ans, a[26][26], b[26][26];
    while(cin >> n >> k) {
        for(int i = 0; i < n * n; i++) {
            row1 = i / n;
            col1 = i % n;
            for(int j = 0; j < n * n; j++) {
                row2 = j / n;
                col2 = j % n;
                if(((row1 == row2) && (abs(col1 - col2) > 1)) ||
                ((col1 == col2) && (abs(row1 - row2) > 1)) ||
                ((abs(row1 - row2) == abs(col1 - col2)) && (abs(row1 - row2) > 1)) ||
                (row1 == row2 && col1 == col2) ||
                (abs(row1 - row2) == 2 && abs(col1 - col2) == 4) ||
                (abs(col1 - col2) == 2 && abs(row1 - row2) == 4)) {
                    a[i][j] = 0;
                } else a[i][j] = 1;
            }
        }
        expbin(a, b, k, n * n);
        ans = 0LL;
        for(int i = 0; i < n * n; i++) {
            for(int j = 0; j < n * n; j++) {
                ans += b[i][j];
                ans %= MOD;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
