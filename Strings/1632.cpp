#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans;
    string word;
    unordered_map<char, int> ltt;
    ltt['a'] = 1;
    ltt['e'] = 1;
    ltt['i'] = 1;
    ltt['o'] = 1;
    ltt['s'] = 1;
    cin >> n;
    while(n--) {
        ans = 1;
        cin >> word;
        for(int i = 0; i < word.size(); i++) {
            if(ltt[(char) tolower(word[i])] == 1) {
                ans *= 3;
            } else ans *= 2;
        }
        cout << ans << "\n";
    }
    return 0;
}
