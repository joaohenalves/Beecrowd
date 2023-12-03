#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<char> number;
    string seq = "ABCD";
    long long n;
    while(cin >> n, n) {
        n *= n;
        do {
            number.push(seq[n % 4]);
            n /= 4;
        } while(n);
        while(!number.empty()) {
            cout << number.top();
            number.pop();
        }
        cout << "\n";
    }
    return 0;
}
