#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, date;
    string name;
    vector<pair<int, string> > meats;
    while(cin >> n) {
        meats.reserve(n);
        for(int i = 0; i < n; i++) {
            cin >> name >> date;
            meats.emplace_back(date, name);
        }
        sort(meats.begin(), meats.end());
        for(int j = 0; j < meats.size() - 1; j++) {
            cout << meats[j].second << " ";
        }
        cout << meats[meats.size()-1].second << "\n";
        meats.clear();
        meats.shrink_to_fit();
    }  
    return 0;
}