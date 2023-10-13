#include <bits/stdc++.h>
using namespace std;

int n, t;

int f(int t, int val[], int dur[], vector<int> &memo) {
    if (t == 0) return 0;
    if (memo[t] != -1) {
        return memo[t];
    }
    int maxPoints = 0;
    for(int i = 0; i < n; i++) {
        if (t - dur[i] >= 0) {
            maxPoints = max(f(t - dur[i], val, dur, memo) + val[i], maxPoints);
        }
    }
    return memo[t] = maxPoints;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int val[100];
    int dur[100];
    int counter = 1;
    while (cin >> n >> t) {
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            cin >> dur[i] >> val[i];
        }
        vector<int> memo(t + 1, -1);
        cout << "Instancia " << counter << "\n" << f(t, val, dur, memo) << "\n\n";
        counter++;
    }
    return 0;
}
