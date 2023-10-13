#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n;
    while(n--) {
        cin >> s;
        sort(s.begin(), s.end());
        cout << s << "\n";
        while(next_permutation(s.begin(), s.end())) {
            cout << s << "\n";
        }
        cout << "\n";
    }
    return 0;
}