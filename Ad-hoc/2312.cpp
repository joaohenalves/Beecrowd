#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int, string> t;
int g1, g2, s1, s2, b1, b2;
string name1, name2;

bool comp(t a, t b) {
    tie(g1, s1, b1, name1) = a;
    tie(g2, s2, b2, name2) = b;
    if(g1 == g2) {
        if(s1 == s2) {
            if(b1 == b2) return name1 < name2;
            return b1 > b2;
        }
        return s1 > s2;
    }
    return g1 > g2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, g, s, b;
    string name;
    cin >> n;
    vector<t> countries(n);
    for(int i = 0; i < n; i++) {
        cin >> name >> g >> s >> b;
        countries[i] = make_tuple(g, s, b, name);
    }
    sort(countries.begin(), countries.end(), comp);
    for(int i = 0; i < n; i++) {
        tie(g, s, b, name) = countries[i];
        cout << name << " " << g << " " << s << " " << b << "\n";
    }
    return 0;
}