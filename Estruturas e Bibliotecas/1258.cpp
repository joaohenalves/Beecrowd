#include <bits/stdc++.h>
using namespace std;

bool comp(tuple<string, string, string> a, tuple<string, string, string> b) {
    if(get<0>(a) == get<0>(b)) {
        if(get<1>(a) == get<1>(b)) {
            return get<2>(a) < get<2>(b);
        }
        return get<1>(a) > get<1>(b);
    }
    return get<0>(a) < get<0>(b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string name, size, color;
    vector<tuple<string, string, string>> shirts;
    cin >> n;
    while(n != 0) {
        for(int i = 0; i < n; i++) {
            getline(cin, name);
            getline(cin, name);
            cin >> color >> size;
            shirts.push_back(make_tuple(color, size, name));
            sort(shirts.begin(), shirts.end(), comp);
        }
        for(auto data : shirts) {
            cout << get<0>(data) << " " << get<1>(data) << " " << get<2>(data) << "\n";
        }
        cin >> n;
        if(n != 0) {
            cout << "\n";
            shirts.clear();
        }
    }
}