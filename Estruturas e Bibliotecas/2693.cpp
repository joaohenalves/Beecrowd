#include <bits/stdc++.h>
using namespace std;

bool comp(tuple<string, string, int> a, tuple<string, string, int> b) {
    if(get<2>(a) == get<2>(b)) {
        if(get<1>(a) == get<1>(b)) {
            return get<0>(a) < get<0>(b);
        }
        return get<1>(a) < get<1>(b);
    }
    return get<2>(a) < get<2>(b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string name, dir;
    vector<tuple<string, string, int>> people;
    int dist;
    for(;;) {
        cin >> n;
        if(cin.eof()) break;
        for(int i = 0; i < n; i++) {
            cin >> name >> dir >> dist;
            people.push_back(make_tuple(name, dir, dist));
        }
        sort(people.begin(), people.end(), comp);
        for(auto names : people) {
            cout << get<0>(names) << "\n";
        }
        people.clear();
    }
    return 0;
}