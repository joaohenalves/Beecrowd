#include <bits/stdc++.h>
using namespace std;
 
#define MAX 112345

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    string s;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        if(s[0] == '1') {
            cout << min(45, n);
            if(n > 45) cout << "+" << n - 45;
            cout << "\n";
        } else {
            cout << min(45, n) + 45;
            if(n > 45) cout << "+" << n - 45;
            cout << "\n";
        }
    }
    return 0;
}

