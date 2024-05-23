#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int prev = -1, next, error = 0;
    while(cin >> next) {
        if(!error) {
            if(next <= prev) {
                error = 1;
            } else {
                prev = next;
            }
        }
    }
    cout << prev + 1 << "\n";
    return 0;
}
