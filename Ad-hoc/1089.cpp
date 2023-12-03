#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int notes[11234];
    int n, first, next, prev, dir, tempDir, ans;
    while(cin >> n, n) {
        ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> notes[i];
        }
        dir = (notes[1] > notes[0]);
        for(int j = 1; j < n; j++) {
            tempDir = (notes[j] > notes[j - 1]);
            if(dir != tempDir) ans++;
            dir = tempDir;
        }
        tempDir = (notes[0] > notes[n - 1]);
        if(dir != tempDir) ans++;
        dir = tempDir;
        tempDir = (notes[1] > notes[0]);
        if(dir != tempDir) ans++;
        dir = tempDir;
        cout << ans << "\n";
    }
    return 0;
}
