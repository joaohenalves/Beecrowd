#include <bits/stdc++.h>
using namespace std;

#define MAX 212345

int v[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int x = 0, o = 0;
    cin >> s;
    for(char c : s) {
        if(c == 'X') x++;
        else o++;
    }
    if(o > x || o == 0) cout << "?\n";
        else {
            if(s[1] == 'X') {
                cout << "Alice\n";
            } else cout << "*\n";
        }
    return 0;
}
