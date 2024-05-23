#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

vector<vector<iii>> auxQueries(MAX);
vector<ii> att(MAX);
int n, bit[MAX], l[MAX], res[MAX];

void setbit(int i, int delta) {
    while(i <= n) {
        bit[i] += delta;
        i += i & -i;
    }
}

int getbit(int i) {
    int ans = 0;
    while(i) {
        ans += bit[i];
        i -= i & -i;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, x, y, q, op, w, idxAtt, idxQr;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i <= n; i++) {
            bit[i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            cin >> l[i];
            setbit(i, l[i]);
        }
        idxAtt = idxQr = 0;
        cin >> q;
        while(q--) {
            cin >> op;
            if(op == 2) {
                cin >> x >> w;
                att[idxAtt++] = make_pair(x, w);
            } else {
                cin >> x >> y >> w;
                auxQueries[w].emplace_back(x, y, idxQr);
                idxQr++;
            }
        }
        for(int i = 0; i <= idxAtt; i++) {
            for(auto &[a, b, c] : auxQueries[i]) {
                res[c] = getbit(b) - getbit(a - 1);
            }
            if(i < idxAtt) {
                setbit(att[i].first, att[i].second - l[att[i].first]);
                l[att[i].first] = att[i].second;
            }
        }
        for(int i = 0; i < idxQr; i++) {
            cout << res[i] << "\n";
        }
        for(int i = 0; i <= idxAtt; i++) {
            auxQueries[i].clear();
        }
    }
}
