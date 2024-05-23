#include <bits/stdc++.h>
using namespace std;

#define MAX 1123
typedef pair<int, int> pii;
#define _ra(i) ((i) < n ? ra[i] : 0)

int n, k, owner[MAX], sa[MAX], lcp[MAX], ra[MAX], tempra[MAX], phi[MAX], plcp[MAX];
string t;

bool cmp(int i, int j) {
    return pii(ra[i], _ra(i + k)) < pii(ra[j], _ra(j + k));
}

void compute_lcp() {
    int i, l;
    phi[sa[0]] = -1;
    for(i = 1; i < n; i++) phi[sa[i]] = sa[i - 1];
    for(i = l = 0; i < n; i++) {
        if(phi[i] == -1) { plcp[i] = 0; continue; }
        while(t[i + l] == t[phi[i] + l]) l++;
        plcp[i] = l--;
        l = max(0, l);
    }
    for(i = 0; i < n; i++) {
        lcp[i] = plcp[sa[i]];
    }
}

void build_sa() {
    int i, r;
    for(i = 0; i < n; i++) {
        sa[i] = i;
        ra[i] = t[i];
    }
    for(k = 1; k < n; k <<= 1) {
        sort(sa, sa + n, cmp);
        tempra[sa[0]] = r = 0;
        for(i = 1; i < n; i++) {
            tempra[sa[i]] = ra[sa[i]] == ra[sa[i - 1]] && 
                _ra(sa[i] + k) == _ra(sa[i - 1] + k) ? r : ++r;
        }
        for(i = 0; i < n; i++) ra[i] = tempra[i];
        if(ra[sa[n - 1]] == n - 1) break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans, first = 1, i;
    string s1, s2;
    while(getline(cin, s1)) {
        getline(cin, s2);
        t = s1; t += "$";
        t += s2; t += "#";
        n = t.size();
        for(i = 0; i < n; i++) owner[i] = i > (int) s1.size();
        build_sa();
        compute_lcp();
        ans = 0;
        for(i = 1; i < n; i++) {
            if(owner[sa[i]] != owner[sa[i - 1]]) {
                ans = max(ans, lcp[i]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
