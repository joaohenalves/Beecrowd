#include <bits/stdc++.h>
using namespace std;
 
#define MAX 212345
#define left(p) ((p) << 1)
#define right(p) (left(p) + 1)
typedef long long ll;
 
ll n, c[MAX], st[4 * MAX], lazy[4 * MAX];

void update_lazy(int p, int l, int r, ll val) {
    ll k = r - l + 1;
    st[p] += k * val;
    if(l < r) {
        lazy[left(p)] += val;
        lazy[right(p)] += val;
    }
    lazy[p] = 0;
}

ll build_st(int p, int l, int r) {
    int m = (l + r) / 2;
    if(l == r) return st[p] = c[l];
    return st[p] = build_st(left(p), l, m) + build_st(right(p), m + 1, r);
}
 
ll query_st(int p, int l, int r, int i, int j) {
    if(lazy[p] > 0) update_lazy(p, l, r, lazy[p]);
    if(r < i || l > j) return 0;
    if(i <= l && r <= j) return st[p];
    int m = (l + r) / 2;
    return query_st(left(p), l, m, i, j) + query_st(right(p), m + 1, r, i, j);
}
 
ll update_st(int p, int l, int r, int i, ll val) {
    if(i < l || i > r) return st[p];
    if(i == l && l == r) return st[p] = val;
    int m = (l + r) / 2;
    return st[p] = update_st(left(p), l, m, i, val) + update_st(right(p), m + 1, r, i, val);
}

ll update_range(int p, int l, int r, int i, int j, ll val) {
    if(lazy[p] > 0) update_lazy(p, l, r, lazy[p]);
    if(r < i || l > j) return st[p];
    if(i <= l && r <= j) {
        update_lazy(p, l, r, val);
        return st[p];
    }
    int m = (l + r) / 2;
    return st[p] = update_range(left(p), l, m, i, j, val) + update_range(right(p), m + 1, r, i, j, val);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q, op, a, b, t;
    ll val;
    cin >> t;
    while(t--) {
        cin >> n >> q;
        memset(st, 0, sizeof(st));
        memset(lazy, 0, sizeof(lazy));
        while(q--) {
            cin >> op;
            if(op == 0) {
                cin >> a >> b >> val;
                a--; b--;
                update_range(1, 0, n - 1, a, b, val);
            } else {
                cin >> a >> b;
                a--; b--;
                cout << query_st(1, 0, n - 1, a, b) << "\n";
            }
        }
    }
    return 0;
}
