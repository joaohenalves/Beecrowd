#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, c, b;
    cin >> t;
    while(t--) {
        cin >> n;
        b = c = 0;
        bitset<14> x(n);
        for(int i = 0; i < 13; i++) {
            if(x[i]) b++;
            else {
                if(b) {
                    c++;
                    if(x[i + 1] == 1 && b > 1) {
                        b = 1;
                    } else {
                        if(b > 1) c++;
                        b = 0;
                    }
                }
            }
        }
        cout << c << "\n";
    }    
    return 0;
}
