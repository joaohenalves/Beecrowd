#include <bits/stdc++.h>
using namespace std;
 
#define MAX 112345
#define INF 112345678
#define left(p) ((p) << 1)
#define right(p) (left(p) + 1)
typedef pair<int, int> ii;

int n, v[MAX];
ii st[4 * MAX];

ii buildst(int p, int l, int r) {
    if(l == r) return st[p] = make_pair(v[l], v[l]);
    int m = (l + r) / 2;
    ii lf = buildst(left(p), l, m);
    ii rt = buildst(right(p), m + 1, r);
    st[p].first = min(lf.first, rt.first);
    st[p].second = max(lf.second, rt.second);
    return st[p];
}

ii queryst(int p, int l, int r, int i, int j) {
    if(l > j || r < i) return make_pair(INF, 0);
    if(l >= i && r <= j) return st[p];
    int m = (l + r) / 2;
    ii lf = queryst(left(p), l, m, i, j);
    ii rt = queryst(right(p), m + 1, r, i, j);
    return make_pair(min(lf.first, rt. first), max(lf.second, rt.second));
}

ii updatest(int p, int l, int r, int i, int val) {
    if(i < l || i > r) return st[p];
    if(i == l && l == r) return st[p] = make_pair(val, val);
    int m = (l + r) / 2;
    ii lf = updatest(left(p), l, m, i, val);
    ii rt = updatest(right(p), m + 1, r, i, val);
    st[p].first = min(lf.first, rt.first);
    st[p].second = max(lf.second, rt.second);
    return st[p];
}

int main() {
    int op, a, b, q;
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }
        buildst(1, 0, n - 1);
        scanf("%d", &q);
        while(q--) {
            scanf("%d %d %d", &op, &a, &b);
            if(op == 1) {
                a--;
                updatest(1, 0, n - 1, a, b);
            } else {
                a--; b--;
                ii ans = queryst(1, 0, n - 1, a, b);
                printf("%d\n", ans.second - ans.first);
            }
        }
    }
    return 0;
}

