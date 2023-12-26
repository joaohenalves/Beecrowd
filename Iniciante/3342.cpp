#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, b, p;
    cin >> n;
    b = ceil(n * n / 2.0);
    p = floor(n * n / 2.0);
    cout << b << " casas brancas e " << p << " casas pretas\n";
    return 0;
}
