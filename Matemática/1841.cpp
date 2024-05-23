#include <bits/stdc++.h>
using namespace std;

#define MAX 1123456
#define MOD 1000000007
#define left(p) ((p) << 1)
#define right(p) (left(p) + 1)
typedef long long ll;

int nsize;
ll num, l[MAX], a[MAX], st[4 * MAX];
unordered_map<ll, int> mp;
set<ll> allPrimes, ans;

ll build_st(ll p, ll lf, ll rg) {
    ll m = (lf + rg) / 2;
    if(lf == rg) return st[p] = a[lf] % MOD;
    return st[p] = (build_st(left(p), lf, m) * build_st(right(p), m + 1, rg)) % MOD;
}

ll query_st(ll p, ll lf, ll rg, ll i, ll j) {
    if(rg < i || lf > j) return 1;
    if(i <= lf && rg <= j) return st[p] % MOD;
    ll m = (lf + rg) / 2;
    return (query_st(left(p), lf, m, i, j) * query_st(right(p), m + 1, rg, i, j)) % MOD;
}

ll update_st(ll p, ll lf, ll rg, ll i, ll val) {
    if(i < lf || i > rg) return st[p] % MOD;
    if(i == lf && lf == rg) return st[p] = val % MOD;
    ll m = (lf + rg) / 2;
    return st[p] = (update_st(left(p), lf, m, i, val) * update_st(right(p), m + 1, rg, i, val)) % MOD;
}

void decomp(ll nx) {
    int exp;
    for(int i = 2; i * i <= nx; i++) {
        exp = 0;
        while(nx % i == 0) {
            nx /= i;
            exp = 1;
        }
        if(exp) ans.insert(i);
    }
    if(nx > 1) ans.insert(nx);
}

void fact() {
    for(auto p : ans) {
        int exp = 0;
        while(num % p == 0) {
            exp++;
            num /= p;
        }
        a[mp[p]] = exp + 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num;
    int x, idx = 0, id = 0;
    decomp(num);
    for(auto p : ans) allPrimes.insert(p);
    while(cin >> x) {
        l[idx++] = x;
        allPrimes.insert(x);
    }
    for(auto p : allPrimes) {
        mp[p] = id++;
    }
    for(int i = 0; i < id; i++) {
        a[i] = 1;
    }
    nsize = id;
    fact();
    build_st(1, 0, nsize - 1);
    for(int i = 0; i < idx; i++) {
        cout << query_st(1, 0, nsize - 1, 0, mp[l[i]] - 1) << "\n";
        update_st(1, 0, nsize - 1, mp[l[i]], a[mp[l[i]]] + 1);
        a[mp[l[i]]]++;
    }
    return 0;
}
