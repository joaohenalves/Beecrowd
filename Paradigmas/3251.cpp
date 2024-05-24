#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2, temp;
    vector<string> str;
    int n, p, loc, flag;
    cin >> s1;
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] != '*') temp.push_back(s1[i]);
        else {
            if(temp.size() > 0) str.push_back(temp);
            temp = "";
        }
    }
    if(temp.size() != 0) str.push_back(temp);
    cin >> n;
    while(n--) {
        cin >> s2;
        flag = 1;
        p = 0;
        if(s1[0] != '*') {
            loc = s2.find(str[0]);
            if(loc != 0) {
                flag = 0;
            } else p += str[0].size();
        }
        for(int i = 0; i < str.size() && flag; i++) {
            if(i == 0 && s1[0] != '*') continue;
            if(i == str.size() - 1 && s1[s1.size() - 1] != '*') continue;
            loc = s2.find(str[i], p);
            if(loc != string::npos) p += str[i].size();
            else { flag = 0; break; }
        }
        if(s1[s1.size() - 1] != '*' && flag) {
            loc = s2.size() - str[str.size() - 1].size();
            if(s2.find(str[str.size() - 1], max(loc, p)) == string::npos) {
                flag = 0;
            }
        } 
        if(flag == 1) cout << s2 << "\n";
    }
    return 0;
}
