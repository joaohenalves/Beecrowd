#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, budget, aux;
    int totalVolume = 0;
    cin >> n >> budget;
    vector<tuple<double, int, int>> cheeses;
    cheeses.reserve(n);
    for(int i = 0; i < n; ++i) {
        cin >> aux;
        cheeses.emplace_back(0, aux, 0);
    }
    for(int j = 0; j < n; ++j) {
        cin >> aux;
        get<0>(cheeses[j]) = (double) aux/get<1>(cheeses[j]);
        get<2>(cheeses[j]) = aux;
    }

    sort(cheeses.begin(), cheeses.end());

    for(int k = 0; k < n; ++k) {
        if(get<2>(cheeses[k]) <= budget) {
            totalVolume += get<1>(cheeses[k]);
            budget -= get<2>(cheeses[k]);
        } else {
            totalVolume += budget/get<0>(cheeses[k]);
            break;
        }
    }
    cout << (int)(-0.5 + sqrt(0.25 + 2 * totalVolume)) << "\n";
}