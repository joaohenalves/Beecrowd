#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> genes (51234);
    int n, inv, bg, ed, cases;
    int number = 1;
    while(cin >> n, n) {
        iota(genes.begin(), genes.begin() + n, 1);
        cin >> inv;
        for(int j = 0; j < inv; j++) {
            cin >> bg >> ed;
            reverse(genes.begin() + (bg - 1), genes.begin() + ed);
        }
        cin >> cases;
        cout << "Genome " << number << "\n";
        for(int k = 0; k < cases; k++) {
            cin >> inv;
            for(int l = 0; l < n; l++) {
                if(genes[l] == inv) {
                    cout << l+1 << "\n";
                }
            }
        }
        number++;
    }
    return 0;
}