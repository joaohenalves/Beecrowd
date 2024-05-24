#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, l1, l2, l3, aux;
    while(cin >> n >> l1 >> l2 >> l3) {
        aux = l2 * l3 / gcd(l2, l3);
        aux = l1 * aux / gcd(l1, aux);
        cout << aux - n << "\n";
    }
    return 0;
}
