#include <bits/stdc++.h>
using namespace std;

int main(void) {

    int n, r, x;
    vector<int> s;

    for(;;) {
        cin >> n;
        if (cin.eof()) break;
        cin >> r;
        for(int i = 0; i < r; i++) {
            cin >> x;
            s.push_back(x);
        }
        for(int j = 1; j <= n; j++) {
            if(find(s.begin(), s.end(), j) == s.end()) {
                cout << j << " ";
            }
        }
        if(n == r) cout << "*";
        cout << "\n";
        s.clear();
    }

    return 0;

}