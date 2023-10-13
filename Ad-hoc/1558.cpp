#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num, res;
    bool flag;
    while(cin >> num) {
        flag = false;
        for(int i = 0; i * i <= num && !flag; i++) {
            for(int j = 0; j * j <= num && !flag; j++) {
                res = i * i + j * j;
                if(res == num) {
                    cout << "YES\n";
                    flag = true;
                } else if(res > num) break;
            }
        }
        if(!flag) cout << "NO\n";
    }
    return 0;
}