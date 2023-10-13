#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, temp, counter, sizeBefore, sizeAfter, sizeAux;
    for(;;) {
        cin >> n >> m;
        if(n == 0) break;
        unordered_set<int> cards;
        unordered_set<int> setAux;
        counter = 0;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            cards.insert(temp);
        }
        sizeBefore = cards.size();
        for(int j = 0; j < m; j++) {
            cin >> temp;
            cards.insert(temp);
            setAux.insert(temp);
        }
        sizeAfter = cards.size();
        sizeAux = setAux.size();
        cout << min(sizeAfter - sizeAux, sizeAfter - sizeBefore) << "\n";
    }
    return 0;
}