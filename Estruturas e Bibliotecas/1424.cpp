#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    int n, m, k, v, temp;
    unordered_map<int, vector<int>> numbers;
    while(cin >> n >> m) {
        for(int i = 0; i < n; i++) {
            cin >> temp;
            numbers[temp].push_back(i+1);
        }
        for(int j = 0; j < m; j++) {
            cin >> k >> v;
            if(k > numbers[v].size()) {
                cout << 0 << "\n";
            } else {
                cout << numbers[v][k-1] << "\n";
            }
        }
        numbers.clear();
    }
    return 0;
}