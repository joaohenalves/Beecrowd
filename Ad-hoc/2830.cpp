#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b) {
    if(a == b) return 0;
    return 1 + solve(a / 2, b / 2);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, ans;
    cin >> a >> b;
    a--; b--;
    ans = solve(a, b);
    switch(ans) {
        case 1:
            cout << "oitavas";
            break;
        case 2:
            cout << "quartas";
            break;
        case 3:
            cout << "semifinal";
            break;
        case 4:
            cout << "final";
    }
    cout << "\n";
    return 0;
}
