#include <bits/stdc++.h>
using namespace std;

int mdc(int num1, int num2) {
    if(num1 % num2 == 0) {
        return num2;
    } else {
        return mdc(num2, num1 % num2);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, n1, n2, result;
    string a, b;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        cin >> b;
        n1 = stoi(a, 0, 2);
        n2 = stoi(b, 0, 2);
        result = mdc(n1, n2);
        if(result == 1) {
            cout << "Pair #" << i + 1 << ": Love is not all you need!\n";
        } else {
            cout << "Pair #" << i + 1 << ": All you need is love!\n";
        }
    }
    return 0;
}