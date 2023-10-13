#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    vector<long long> fact (21);
    fact[0] = 1;
    long long temp, a, b;
    for(int i = 1; i < 21; i++) {
        temp = 1;
        for(int j = 1; j <= i; j++) {
            temp *= j;
        }
        fact[i] = temp;
    }
    while(cin >> a >> b) {
        cout << fact[a] + fact[b] << "\n";
    }
    return 0;
}