#include <bits/stdc++.h>
using namespace std;

map<char, int> k;
string prfx, infx;
int idx;

void postFix(int l, int r) {
    if(l <= r) {
        idx++;
        int current = k[prfx[idx]];
        postFix(l, current - 1);
        postFix(current + 1, r);
        cout << infx[current];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> prfx >> infx) {
        idx = -1;
        for(int i = 0; i < infx.size(); i++) {
            k[infx[i]] = i;
        }
        postFix(0,  infx.size() - 1);
        cout << "\n";
    }
    return 0;
}
