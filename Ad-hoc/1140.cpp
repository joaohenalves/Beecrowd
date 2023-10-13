#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    bool flag;
    while(getline(cin, s), s[0] != '*') {
        flag = true;
        for(int i = 1; i < s.size(); i++) {
            if(s[i - 1] == ' ') {
                if(!(s[i] == s[0] || s[i] == s[0] + 32 || s[i] == s[0] - 32))
                    flag = false;
            }
        }
        cout << (flag ? "Y\n" : "N\n");
    }

    return 0;
}