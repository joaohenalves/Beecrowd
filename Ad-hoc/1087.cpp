#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans, x1, x2, y1, y2;
    while(cin >> x1 >> y1 >> x2 >> y2, x1) {
        if(x1 == x2 && y1 == y2) ans = 0;
        else if(x1 == x2 || y1 == y2 || (abs(x1 - x2) == abs(y1 - y2))) ans = 1;
        else ans = 2;
        cout << ans << "\n";
    }
    return 0;
}
