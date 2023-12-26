#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    while(cin >> a) {
        if(a[0] == '-') break;
        if(a[0] == '0') {
           cout << dec << stoi(a, nullptr, 16) << "\n";
        } else {
            cout << "0x" << uppercase << hex << stoi(a) << "\n";
        }
    }
    return 0;
}
