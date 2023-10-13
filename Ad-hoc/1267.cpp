#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bitset<100> dinners;
    int a, b, temp;
    bool cond;
    while(cin >> a >> b, a) {
        cond = false;
        dinners.set();
        for(int i = 0; i < b; i++) {
            for(int j = 0; j < a; j++) {
                cin >> temp;
                dinners[j] = temp & dinners[j];
            }
        }
        for(int k = 0; k < a; k++) {
            if(dinners[k]) {
                cond = true;
                break;
            }
        }
        cout << (cond ? "yes\n" : "no\n");
    }
    return 0;
}