#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p, w, acc, counter, temp;
    cin >> n;
    while(n--) {
        acc = 0;
        counter = 0;
        cin >> p >> w;
        while(p--) {
            cin >> temp;
            if(acc + temp <= w) {
                acc += temp;
            } else {
                counter++;
                acc = temp;
            }
        }
        if(acc) counter++;
        cout << counter << "\n";
    }
    return 0;
}