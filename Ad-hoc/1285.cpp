#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    int n, m, counter;
    while(cin >> n >> m) {
        counter = 0;
        for(int i = n; i <= m; i++) {
            set<char> letters;
            str = to_string(i);
            for(int j = 0; j <  str.size(); j++) {
                letters.insert(str[j]);
            }
            if(letters.size() == str.size()) counter++;
        }
        cout << counter << "\n";
    }

    return 0;
}