#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s, p, m, g;
    int counter = 0;
    string titans;
    cin >> n >> s >> titans >> p >> m >> g;
    list<int> walls;
    walls.emplace_back(s);
    unordered_map<char, int> tts;
    tts['G'] = g;
    tts['M'] = m;
    tts['P'] = p;

    for(int j = 0; j < n; j++) {

        auto it = find_if(walls.begin(), walls.end(), [&](int value) {
            return value >= tts[titans[j]];
        });
        if(it == walls.end()) {
            walls.emplace_back(s);
            it = prev(walls.end());
        }
        *it -= tts[titans[j]];
        if(*it < p) {
            walls.erase(it);
            counter++;
        }

    }

    int result = walls.size();

    cout << result + counter << "\n";

    return 0;
}