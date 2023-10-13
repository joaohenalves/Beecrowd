#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string name;
    double n, counter;
    double fraction;
    map<string, int> trees;
    cin >> n;
    getline(cin, name);
    getline(cin, name);
    for(int i = 0; i < n; i++) {
        counter = 0;
        for(;;) {
            getline(cin, name);
            if(name.size() == 0 || cin.eof()) break;
            trees[name]++;
            counter++;
        }
        for(auto data: trees) {
            fraction = data.second * (100/counter);
            cout << data.first;
            cout << fixed;
            cout.precision(4);
            cout << " " << fraction << "\n";
        }
        trees.clear();
        if(i != n - 1) cout << "\n";
    }

    return 0;
}