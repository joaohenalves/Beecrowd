#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;

bool isValid(int n) {
    if(n % a == 0 && n % b != 0 && d % n != 0) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x = -1;
    cin >> a >> b >> c >> d;
    for(int n = 1; n * n <= c; n++) {
        if(c % n == 0) {
            if(isValid(n)) {
                x = n;
                break;
            }
            if(isValid(c / n)) x = c / n;
        }
    }
    cout << x << "\n";
    return 0;
}
