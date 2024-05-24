#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    scanf("%d.%d", &a, &b);
    int R = 100 * a + b;
    cout << lcm(36000, R) / R << "\n";
    return 0;
}
