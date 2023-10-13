#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, counter = 0, flag = 0, pos;
    cin >> n;
    for(;;) {
        if(pos < n/2) {
            pos = (pos + 1) + pos;
        } else {
            pos = (pos % (n/2)) * 2;
        }
        counter++;
        if(pos == 0) break;
        if(pos == n - 1) {
            flag = 1;
            break;
        }
    }
    cout << (flag ? counter * 2 : counter) << "\n";
    return 0;
}