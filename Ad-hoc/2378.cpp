#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, c, s, e, saldo = 0, flag = 0;
    cin >> n >> c;
    while(n--) {
        cin >> s >> e;
        saldo -= s;
        saldo += e;
        if(saldo > c) {
            flag = 1;
        }
    }
    cout << (flag ? "S\n" : "N\n");
    return 0;
}
