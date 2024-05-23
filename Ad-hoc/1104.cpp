// USANDO SET

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
        set<int> cards;
        set<int> setAux;
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


//USANDO BITSET

#include <bits/stdc++.h>
using namespace std;

bitset<112345> cardsA;
bitset<112345> cardsB;
bitset<112345> auxSet;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, aux, aux2;
    while(cin >> a >> b, a) {
        for(int i = 0; i < a; i++) {
            cin >> aux;
            cardsA[aux] = 1;
        }
        for(int i = 0; i < b; i++) {
            cin >> aux;
            cardsB[aux] = 1;
        }
        auxSet = cardsB;
        cardsB &= ~cardsA;
        cardsA &= ~auxSet;
        cout << min(cardsA.count(), cardsB.count()) << "\n";
        cardsA.reset();
        cardsB.reset();
    }
    return 0;
}
