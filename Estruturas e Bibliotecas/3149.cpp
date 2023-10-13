#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> pis;

bool comp(pis a, pis b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, min;
    string name, hour;
    cin >> min >> n;
    vector<pis> people;
    for(int i = 0; i < n; i++) {
        cin >> hour >> name;
        if(hour[0] == '2') {
            if(60 - stoi(hour.substr(3, 2)) <= min)
                people.emplace_back((60 - stoi(hour.substr(3, 2))) * -1, name);
        } else {
            if(stoi(hour.substr(3, 2)) <= min)
                people.emplace_back(stoi(hour.substr(3, 2)), name);
        }
    }
    stable_sort(people.begin(), people.end(), comp);
    for(auto p : people) {
        cout << p.second << "\n";
    } 
    return 0;
}