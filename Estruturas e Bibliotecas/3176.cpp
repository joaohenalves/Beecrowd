#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> pis;

bool comp(pis a, pis b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<pis> goblins;
    int n, age, factor;
    string name;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> name >> age;
        goblins.emplace_back(age, name);
    }
    sort(goblins.begin(), goblins.end(), comp);
    factor = goblins.size() / 3;
    for(int j = 0; j < factor; j++) {
        cout << "Time " << j + 1 << "\n";
        cout << goblins[j].second << " " << goblins[j].first << "\n";
        cout << goblins[factor + j].second << " " << goblins[factor + j].first << "\n";
        cout << goblins[2 * factor + j].second << " " << goblins[2 * factor + j].first << "\n\n";
    }
    return 0;
}