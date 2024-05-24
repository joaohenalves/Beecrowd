#include <bits/stdc++.h>
using namespace std;

#define MAX 212

int n, mat[MAX][MAX];

void floydWarshall() {
    int i, j, k;
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                mat[i][j] |= mat[i][k] & mat[k][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v, w, counter, flag;
    char c;
    string s;
    while(cin >> n, n) {
        memset(mat, 0, sizeof(mat));
        while(cin >> u >> v, u) {
            cin.ignore();
            cin >> s;
            u--; v--;
            for(char c : s) {
                mat[u][v] |= 1 << (c - 'a');
            }
        }
        floydWarshall();
        while(cin >> u >> v, u) {
            u--; v--;
            w = mat[u][v];
            counter = flag = 0;
            while(w) {
                if(w & 1) {
                    cout << static_cast<char>(counter + 'a');
                    flag = 1;
                }
                counter++;
                w >>= 1;
            }
            if(flag == 0) cout << '-';
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
