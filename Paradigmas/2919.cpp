#include <bits/stdc++.h>
using namespace std;

#define MAX 512345

int l[MAX];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s, val;
    while(cin >> n) {
        s = 0;
        for(int i = 0; i < n; i++) {
            cin >> val;
            int it = lower_bound(l, l + s, val) - l;
            if(it == s) l[s++] = val;
            else l[it] = val;
        }
        cout << s << "\n";
    }
    return 0;
}
