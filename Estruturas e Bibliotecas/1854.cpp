#include <bits/stdc++.h>
using namespace std;

#define MAX 1123
#define MAX_FACT 10000012
#define MOD 1000000007
typedef long long ll;

int n, m, bit[MAX][MAX], grid[MAX][MAX];
ll fact[MAX_FACT];

void setbit(int x, int y, int delta) {
    for(int i = x; i <= n; i += i & -i) {
        for(int j = y; j <= m; j += j & -j) {
            bit[i][j] += delta;
        }
    }
}


int getbit(int x, int y) {
    int ans = 0;
    for(int i = x; i > 0; i -= i & -i) {
        for(int j = y; j > 0; j -= j & -j) {
            ans += bit[i][j];
        }
    }
    return ans;
}

ll expbin(ll a, ll b) {
    if(b == 0) return 1;
    if(b & 1) return (a * expbin(a, b - 1)) % MOD;
    ll c = expbin(a, b >> 1);
    return (c * c) % MOD;
}

ll binom(int a, int b) {
    ll c = (fact[b] * fact[a - b]) % MOD;
    return (fact[a] * expbin(c, MOD - 2)) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int day = 1, b, i, v[5];
    memset(bit, 0, sizeof(bit));
    memset(grid, 0, sizeof(grid));
    fact[0] = 1;
    for(int f = 1; f < MAX_FACT; f++) {
        fact[f] = (fact[f - 1] * f) % MOD;
    }
    cin >> n >> m;
    cin.ignore();
    while(getline(cin, s)) {
        i = 0;
        istringstream iss(s);
        while(iss >> v[i]) { i++; }
        switch(i) {
            case 2:
                setbit(v[0], v[1], -grid[v[0]][v[1]]);
                grid[v[0]][v[1]] = 0;
                break;
            case 3:
                grid[v[0]][v[1]] += v[2];
                setbit(v[0], v[1], v[2]);
                break;
            case 5:
                b = getbit(v[2], v[3]) - getbit(v[2], v[1] - 1) 
                - getbit(v[0] - 1, v[3]) + getbit(v[0] - 1, v[1] - 1);
                cout << "Day #" << day << ": " << (b ? binom(v[4] + b - 1, b - 1) : 0) << "\n";
                day++;
                break;
        }
    }
    return 0;
}
