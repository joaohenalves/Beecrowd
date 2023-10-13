#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n, a, b, c, cp, counter;
    cin >> n;
    while(n != 0) {
        cp = 2;
        counter = 0;
        for(int i = 0; i < n; i++) {
            cin >> a >> b >> c;
            if(cp == 1) {
                if(a == 1) {
                    if(b == 0) {
                        cp = 2;
                        counter++;
                    } else {
                        cp = 3;
                        counter += 2;
                    }
                }
            } else if(cp == 2) {
                if(b == 1) {
                    counter++;
                    if(a == 0) {
                        cp = 1;
                    } else {
                        cp = 3;
                    }
                }
            } else {
                if(c == 1) {
                    if(b == 0) {
                        cp = 2;
                        counter++;
                    } else {
                        cp = 1;
                        counter += 2;
                    }
                }
            }
        }
        cout << counter << "\n";
        cin >> n;
    }
    return 0;
}