#include <bits/stdc++.h>
using namespace std;

 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> fib(40);
    vector<int> rec(40);
    fib[1] = rec[0] = rec[1] = 1;
    for(int i = 2; i < 41; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        rec[i] = rec[i - 1] + rec[i - 2] + 1;
    }
    int n, num;
    cin >> n;
    for(int j = 0; j < n; j++) {
        cin >> num;
        cout << "fib(" << num << ") = " << rec[num] - 1 << " calls = " << fib[num] << "\n";
    }
    return 0;
}