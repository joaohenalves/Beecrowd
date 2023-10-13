#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    long long fact[16];
    fact[0] = 1;
    for(int i = 1; i < 16; i++) fact[i] = fact[i - 1] * i;
    while(cin >> s, s[0] != '0') cout << fact[s.size()] << "\n";
    return 0;
}