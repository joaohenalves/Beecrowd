#include <bits/stdc++.h>
using namespace std;

const int INF = 99999999;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int furos, circ, tam1, tam2, temp, diff;
    while(cin >> furos >> circ >> tam1 >> tam2) {
        vector<int> listaFuros;
        vector<int> memo(furos + 1, INF);
        for(int i = 0; i < furos; i++) {
            cin >> temp;
            listaFuros.emplace_back(temp);
        }
        memo[0] = 0;
        for(int j = 1; j <= furos; j++) {
            for(int k = 0; k < j; k++) {
                diff = listaFuros[j - 1] - listaFuros[k];
                if(diff <= tam1) memo[j] = min(memo[j], memo[k] + tam1);
                if(diff <= tam2) memo[j] = min(memo[j], memo[k] + tam2);
            }
        }
        cout << memo[furos] << "\n";
    }
    return 0;
}
