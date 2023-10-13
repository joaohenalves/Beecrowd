#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
#define left(p) ((p) << 1)
#define right(p) (left(p) + 1)

int n, k, a[MAX], st[4 * MAX];

int build_st(int p, int l, int r) {
    int m = (l + r) / 2;
    if(l == r) return st[p] = a[l];
    return st[p] = build_st(left(p), l, m) * build_st(right(p), m + 1, r);
}

int query_st(int p, int l, int r, int i, int j) {
    if(r < i || l > j) return 1;
    if(i <= l && r <= j) return st[p];
    int m = (l + r) / 2;
    return query_st(left(p), l, m, i, j) * query_st(right(p), m + 1, r, i, j);
}

int update_st(int p, int l, int r, int i, int val) {
    if(i < l || i > r) return st[p];
    if(i == l && l == r) return st[p] = val;
    int m = (l + r) / 2;
    return st[p] = update_st(left(p), l, m, i, val) * update_st(right(p), m + 1, r, i, val);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char op;
    int i, j, ans;
    while(cin >> n >> k) {
        for(int l = 0; l < n; l++) {
            cin >> a[l];
            if(a[l]) a[l] /= abs(a[l]);
        }
        build_st(1, 0, n - 1);
        while(k--) {
            cin >> op >> i >> j;
            switch(op) {
                case 'C':
                    i--;
                    if(j) j /= abs(j);
                    update_st(1, 0, n - 1, i, j);
                    break;
                case 'P':
                    i--; j--;
                    ans = query_st(1, 0, n - 1, i, j);
                    cout << (ans ? (ans > 0 ? '+' : '-') : '0');
            }
        }
        cout << "\n";
    }
    return 0;
}