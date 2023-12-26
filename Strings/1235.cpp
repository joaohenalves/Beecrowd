#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, sz;
    string s;
    cin >> n;
    getline(cin, s);
    while(n--) {
        getline(cin, s);
        sz = s.size();
        for(int i = (s.size() / 2) - 1; i >= 0; i--) cout << s[i];
        for(int i = s.size() - 1; i >= s.size() / 2; i--) cout << s[i];
        cout << "\n";
    }
    return 0;
}
