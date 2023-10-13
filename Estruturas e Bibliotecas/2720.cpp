#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

bool comp(ii a, ii b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, p, k, id, aux, vol;
    cin >> t;
    while(t--) {
        cin >> p >> k;
        vector<ii> presents;
        while(p--) {
            vol = 1;
            cin >> id;
            for(int j = 0; j < 3; j++) { cin >> aux; vol *= aux; }
            presents.emplace_back(vol, id);
        }
        sort(presents.begin(), presents.end(), comp);
        vector<int> selected;
        for(int i = 0; i < k; i++) {
            selected.push_back(presents[i].second);
        }
        sort(selected.begin(), selected.end());
        for(int i = 0; i < k; i++) cout << selected[i] << (i == k-1 ? "" : " ");
        cout << "\n";
    }
    return 0;
}