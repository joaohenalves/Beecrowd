#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, flag;
    cin >> t;
    while(t--) {
        cin >> n;
        flag = 0;
        if(n != 2 && (n & 1) == 0) flag = 1;
        for(int i = 3; i * i <= n && flag == 0; i += 2) {
            if(n % i == 0) flag = 1;
        }
        cout << (flag ? "Not " : "") << "Prime\n";
    }
    return 0;
}
