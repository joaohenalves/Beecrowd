#include <bits/stdc++.h>
using namespace std;

#define MAX 112

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> names(MAX);
    int i, n, k, inf, idx, c = 1;
    while(cin >> n >> k, n) {
        inf = 0;
        for(i = 0; i < n; i++) {
            cin >> names[i];
        }
        while(k && inf < n) {
            idx = inf;
            for(i = inf + 1; i < n; i++) {
                if(names[idx] > names[i] && i - k <= inf) {
                    idx = i;
                }
            }
            for(i = idx; i > inf && k; i--) {
                swap(names[i], names[i - 1]);
                k--;
            }
            inf++;
        }
        cout << "Instancia " << c << "\n";
        for(i = 0; i < n; i++) {
            cout << names[i] << " ";
        }
        cout << "\n\n";
        c++;
    }
    return 0;
}
