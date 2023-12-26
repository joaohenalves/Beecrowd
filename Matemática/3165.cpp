#include <bits/stdc++.h>
using namespace std;

bool isPrime[1123];

void sieve() {
    memset(isPrime, 1, sizeof(isPrime));
    for(int i = 2; i * i <= 1123; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j < 1123; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, f = 0, s = 0;
    sieve();
    cin >> n;
    for(int i = n; i >= 2; i--) {
        if(isPrime[i]) {
            if(f == 0) f = i;
            else if(s == 0) {
                s = i;
                if(f - s == 2) break;
            } else {
                f = s;
                s = i;
                if(f - s == 2) break;
            }
        }
    }
    cout << s << " " << f << "\n";
    return 0;
}
