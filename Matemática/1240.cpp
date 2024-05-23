#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, flag;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        flag = 0;
        if(a < b) flag = 1;
        else {
            a -= b;
            b = (int) pow(10, (int) floor(log10(b)) + 1);
            if(a % b != 0) flag = 1;
        }
        cout << (flag ? "nao " : "") << "encaixa\n";
    }
    return 0;
}
