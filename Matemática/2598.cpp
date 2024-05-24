#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double a, b;
    int t;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << ceil(a / b) << "\n";
    }
    return 0;
}
