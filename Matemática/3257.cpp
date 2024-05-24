#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

int trees[MAX];

bool comp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, h = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> trees[i];
    }
    sort(trees, trees + n, comp);
    for(int i = n - 1; i >= 0; i--) {
        h = max(trees[i] + 2 + i, h);
    }
    cout << h << "\n";
    return 0;
}
