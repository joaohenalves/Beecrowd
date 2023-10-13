#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long totalCost, totalPeople;
    int n, people, cost;
    int counter = 1;
    int highest = 0;
    int div;
    cin >> n;
    while(n != 0) {
        totalCost = 0;
        totalPeople = 0;
        highest = 0;
        vector<int> houses (201);
        for(int i = 0; i < n; i++) {
            cin >> people >> cost;
            totalCost += cost;
            totalPeople += people;
            div = cost/people;
            houses[div] += people;
            if(div > highest) highest = div;
        }
        cout << "Cidade# " << counter << ":\n";
        for(int j = 0; j < highest + 1; j++) {
            if(houses[j] != 0) { 
                cout << houses[j] << "-" << j;
                if(j != highest) cout << " ";
                else cout << "\n";
            }
        }
        cout << "Consumo medio: ";
        cout << fixed;
        cout.precision(2);
        cout << floor(((long double) totalCost / totalPeople) * 100.0) / 100.0 << " m3.\n";
        counter++;
        cin >> n;
        if(n != 0) cout << "\n";
    }
    return 0;
}