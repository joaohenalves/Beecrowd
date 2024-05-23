#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if(s == "oposicao" || s == "contrariedade") {
        cout << "mas\n";
    } else cout << "mais\n";
    return 0;
}
