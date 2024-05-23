#include <iostream>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n, n) {
        int s1 = 0, i1 = 0, s2 = 0, i2 = 0, x;
        for(int i = 1; i <= n; i++) {
            cin >> x;
            if(x > s1) {
                i2 = i1;
                s2 = s1;
                i1 = i;
                s1 = x;
            } else if(x > s2) {
                i2 = i;
                s2 = x;
            }
        }
        cout << i2 << "\n";
    }
    return 0;
}
