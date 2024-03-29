#include <bits/stdc++.h>
using namespace std;

#define MAX 512345

vector<string> dna(51);
int table[51][MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, idx, mx, p;
    string s;
    cin >> n >> m;
    for(int i = 0 ; i < m; i++) {
        cin >> dna[i];
    }
    cin >> s;
    for(int i = 0; i < m; i++) {
        table[i][n] = 0;
        for(int j = n - 1; j >= 0; j--) {
            if(dna[i][j] == s[j]) table[i][j] = table[i][j + 1] + 1;
            else table[i][j] = 0;
        }
    }
    p = 0;
    while(p < n) {
        mx = 0;
        for(int i = 0; i < m; i++) {
            if(table[i][p] > mx) {
                mx = table[i][p];
                idx = i;
            }
        }
        if(mx) {
            cout << s.substr(p, mx) << " " << idx + 1 << "\n";
            p += mx;
        } else {
            cout << s[p] << " " << -1 << "\n";
            p++;
        }
    }
    return 0;
}
