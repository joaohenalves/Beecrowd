#include <bits/stdc++.h>
using namespace std;

int notes[41234];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans, total;
    double med;
    while(cin >> n) {
        ans = 1;
        total = 0;
        for(int i = 0; i < n; i++) {
            cin >> notes[i];
            total += notes[i];
        }
        med = total / (double) n;
        if(ceil(med) != med) cout << -1 << "\n";
        else {
            for(int i = 0; i < n; i ++) {
                if(notes[i] < med) ans += med - notes[i];
                else ans += notes[i] - med;
            }
            cout << (ans / 2) + 1 << "\n";
        }
    }    
    return 0;
}
