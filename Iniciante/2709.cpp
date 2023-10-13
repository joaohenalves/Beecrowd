#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, step, a, total, flag;
    while(cin >> n) {
        a = n - 1;
        total = 0;
        flag = 0;
        vector<int> coins(n);
        for(int i = 0; i < n; i++) {
            cin >> coins[i];
        }
        cin >> step;
        while(a >= 0) {
            total += coins[a];
            a -= step;
        }
        for(int i = 2; i <= sqrt(total); i++) {
            if(total % i == 0) {
                flag = true;
                break;
            }
        }
        if(total == 1) flag = true;
        cout << (flag ? "Bad boy! I’ll hit you." : "You’re a coastal aircraft, Robbie, a large silver aircraft.") << "\n";
    }
    return 0;
}