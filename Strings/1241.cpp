#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s1, s2;
    cin >> n;
    while(n--) {
        cin >> s1 >> s2;
        if(s1.size() >= s2.size() && s1.substr(s1.size() - s2.size(), s2.size()) == s2) {
            cout << "encaixa\n";
        } else cout << "nao encaixa\n";
    }
    return 0;
}
