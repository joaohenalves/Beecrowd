#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ibegin, iend, search, sum;
    while(cin >> n) {
        vector<int> shelf(101, 0);
        sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> ibegin >> iend;
            for(int j = ibegin; j < iend + 1; j++) {
                shelf[j]++;
            }
        }
        cin >> search;
        if(shelf[search] == 0) {
            cout << search << " not found\n";
            continue;
        }
        for(int k = 0; k < 101; k++) {
            if(k != search) sum += shelf[k];
            else if (k == search) {
                cout << search << " found from " << sum << " to " << sum + shelf[k] - 1 << "\n";
            }
        }
    }
    return 0;
}