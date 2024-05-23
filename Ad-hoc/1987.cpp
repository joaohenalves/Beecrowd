#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, total;
    char c;
    while(cin >> n) {
        total = 0;
        while(n--) {
            cin >> c;
            total += c - 48;
        }
        cout << total << (total % 3 == 0 ? " sim" : " nao") << "\n";
    }
    return 0;
}
