#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y, z;
    int max = 0;
    int index;
    cin >> x >> y;
    vector <int> vet (x, 0);
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            cin >> z;
            vet[j] += z;
        }
    }
    for(int k = 0; k < x; k++) {
        if(vet[k] >= max) {
            max = vet[k];
            index = k;
        }
    }
    cout << index + 1 << "\n";
    return 0;
}