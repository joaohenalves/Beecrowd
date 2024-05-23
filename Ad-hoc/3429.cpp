#include <bits/stdc++.h>
using namespace std;
 
unordered_map<string, int> ums;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, occ = 0;
    string s, lowest;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == '*') {
                for(int k = 0; k < 26; k++) {
                    s[j] = 'a' + k;
                    ums[s]++;
                    if(ums[s] > occ) {
                        occ = ums[s];
                        lowest = s;
                    } else if(ums[s] == occ && s < lowest) {
                        lowest = s;
                    }
                }
                break;
            }
        }
    }
    cout << lowest << " " << occ << "\n";
    return 0;
}
