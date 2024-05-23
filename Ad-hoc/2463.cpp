#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, prev, next;
    cin >> n;
    prev = m = 0;
    for(int i = 0; i < n; i++) {
        cin >> next;
        prev = max(prev + next, next);
        m = max(prev, m);
    }
    cout << m << "\n";
    return 0;
}
