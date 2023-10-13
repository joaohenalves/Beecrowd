#include <bits/stdc++.h>
using namespace std;

typedef pair<char, int> ci;

bool comp(ci a, ci b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c;
    int flag = 0;
    for(;;) {
        vector<ci> vet;
        unordered_map<char, int> mp;
        for(;;) {
            c = getchar();
            if (c == EOF || c == '\n') break;
            mp[c]++;
        }
        if (c == EOF) break;
        else if(flag) cout << "\n";
        for (auto p : mp) vet.emplace_back(p);
        sort(vet.begin(), vet.end(), comp);
        for (int i = 0; i < vet.size(); i++) {
            cout << (int) vet[i].first << " " << vet[i].second << "\n";
        }
        flag = 1;
    }
    return 0;
}