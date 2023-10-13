#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, total = 0, counter = 0;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'a') {
            counter++;
        }
        if(s[i] == 'b' || i == s.size() - 1) {
            if(counter > 1) total += counter;
            counter = 0;
        }
    }
    cout << total << "\n";
    return 0;
}