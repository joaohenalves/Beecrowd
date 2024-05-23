#include <bits/stdc++.h>
using namespace std;
 
#define MAX 112345
#define INF 112345678
#define left(p) ((p) << 1)
#define right(p) (left(p) + 1)
typedef long long ll;

struct node {
    ll sum, pref, suff, ans;
    ll ss, ps, fs, as;
};

ll n, v[MAX];
node st[4 * MAX];

node combine(node l, node r) {
    node res;
    res.sum = l.sum + r.sum;
    res.ss = l.ss + r.ss;
    if(l.pref > l.sum + r.pref) {
        res.pref = l.pref;
        res.ps = l.ps;
    } else {
        res.pref = l.sum + r.pref;
        res.ps = l.ss + r.ps;
    }
    if(r.suff > r.sum + l.suff) {
        res.suff = r.suff;
        res.fs = r.fs;
    } else {
        res.suff = r.sum + l.suff;
        res.fs = r.ss + l.fs;
    }
    if(max(max(l.ans, r.ans), l.suff + r.pref) == l.suff + r.pref) {
        res.ans = l.suff + r.pref;
        res.as = l.fs + r.ps;
    } else if(max(max(l.ans, r.ans), l.suff + r.pref) == r.ans) {
        res.ans = r.ans;
        res.as = r.as;
    } else {
        res.ans = l.ans;
        res.as = l.as;
    }
    return res;
}

node makeNode(ll val) {
    node res;
    res.sum = res.pref = res.suff = res.ans = val;
    res.ss = res.ps = res.fs = res.as = 1;
    return res;
}

node buildst(int p, int l, int r) {
    if(l == r) return st[p] = makeNode(v[l]);
    int m = (l + r) / 2;
    node lf = buildst(left(p), l, m);
    node rt = buildst(right(p), m + 1, r);
    return st[p] = combine(lf, rt);
}

node queryst(int p, int l, int r, int i, int j) {
    if(l > j || r < i) return makeNode(-INF);
    if(l >= i && r <= j) return st[p];
    int m = (l + r) / 2;
    return combine(queryst(left(p), l, m, i, j), queryst(right(p), m + 1, r, i, j));
}

node updatest(int p, int l, int r, int i, ll val) {
    if(i < l || i > r) return st[p];
    if(i == l && l == r) return st[p] = makeNode(val);
    int m = (l + r) / 2;
    node lf = updatest(left(p), l, m, i, val);
    node rt = updatest(right(p), m + 1, r, i, val);
    return st[p] = combine(lf, rt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, q, a, b;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        buildst(1, 0, n - 1);
        cin >> q;
        while(q--) {
            cin >> a >> b;
            a--; b--;
            node nd = queryst(1, 0, n - 1, a, b);
            cout << nd.ans << " " << nd.as << "\n";
        }
    }
    return 0;
}

