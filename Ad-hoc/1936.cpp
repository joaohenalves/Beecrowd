#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, res;
    int counter = 0;
    bool flag = false;
    cin >> n;
    vector<int> fact;
    for(int i = 1; i < n && !flag; i++) {
        res = 1;
        for(int j = 1; j <= i; j++) {
            res *= j;
        }
        if(res > n) break;
        else fact.push_back(res);
    }
    res = 0;
    for(auto it = fact.rbegin(); it != fact.rend(); it++) {
        while(res + *it <= n) {
            res += *it;
            counter++;
        }
    }

    cout << counter << "\n";
    return 0;
}