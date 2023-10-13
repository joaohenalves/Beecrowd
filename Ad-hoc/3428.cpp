#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, temp, counter = 0;
    cin >> n;
    int lastHit[1000001] = {0};
    for(int i = 0; i < n; i++) {
        cin >> temp;
        if(lastHit[temp] == 0) {
            counter++;
        } else {
            lastHit[temp]--;
        }
        lastHit[temp - 1]++;
    }
    cout << counter << "\n";
    return 0;
}