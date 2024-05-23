#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, counter;
    char c1;
    string s, ans;
    while(cin >> c1, c1 != '0') {
        cin >> s;
        ans = "";
        counter = 0;
        for(auto c : s) {
            if(c != c1) {
                ans.push_back(c);
            }
        }
        for(int i = 0; i < ans.size(); i++) {
            if(ans[i] == '0') counter++;
            else break;
        }
        if(counter == ans.size()) cout << 0 << "\n";
        else {
            cout << ans.substr(counter > 0 ? counter : 0) << "\n";
        }
    }
    return 0;
}
