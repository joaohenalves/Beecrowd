#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int memo[112];
    memo[0] = 0;
    for(int i = 1; i <= 100; i++) {
        memo[i] = memo[i - 1] + i * i;
    }
    while(cin >> n, n) {
        cout << memo[n] << "\n";
    }
    return 0;
}
