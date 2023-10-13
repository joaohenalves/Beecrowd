#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> presents;
    vector<int> pairs;
    int x, y, m, xc, yc;
    while(cin >> x >> y >> m) {
        if(x < y) swap(x, y);
        for(int i = 0; i < m; i++) {
            cin >> xc >> yc;
            if(xc < yc) swap(xc, yc);
            if(yc <= y && xc <= x) {    
                cout << "Sim\n";
            } else {
                cout << "Nao\n";
            }
        }
    }
}