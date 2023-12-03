#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int counter, limit;
    string a, b;
    cin >> a >> b;
    vector<vector<int> > indexes(26);
    vector<int> possibilities(a.size());
    limit = a.size() - b.size() + 1;
    counter = limit;
    for(int i = 0; i < b.size(); i++) {
        indexes[b[i] - 'A'].push_back(i);
    }
    for(int j = 0; j < a.size(); j++) {
        for(int k = 0; k < indexes[a[j] - 'A'].size(); k++) {
            if(j - indexes[a[j] - 'A'][k] >= 0) {
                if(possibilities[j - indexes[a[j] - 'A'][k]] == 0 && j - indexes[a[j] - 'A'][k] < limit) counter--;
                possibilities[j - indexes[a[j] - 'A'][k]] = 1;
            }
        }
    }
    cout << counter << "\n";
    return 0;
}
