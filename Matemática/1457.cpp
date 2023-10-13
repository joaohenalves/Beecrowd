#include <bits/stdc++.h>
using namespace std;

long long fact(int a, int b, int k) {
    if(a - (b * k) <= 0) return 1;
    return (a - (k * b)) * fact(a, b, k + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, n1, n2;
    long long var;
    string a, num;
    cin >> n;
    getline(cin, a);
    for(int i = 0; i < n; i++) {
        getline(cin, a);
        num = "";
        for(int j = 0; j < a.size(); j++) {
            if(a[j] != '!') {
                num.push_back(a[j]);
            } else {
                n2 = a.size() - j;
                break;
            }
        }
        n1 = stoi(num);
        var = fact(n1, n2, 0);
        cout << var << "\n";
    }
    return 0;
}