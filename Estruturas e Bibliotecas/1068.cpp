#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<string> stk;
    bool flag = true;
    string s;

    while(cin >> s) {
        for(long unsigned int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                stk.push("(");
            } else if(s[i] == ')') {
                if(stk.empty()) {
                    flag = false;
                    break;
                } else {
                    stk.pop();
                }
            }
        }
        if (!flag || !stk.empty()) {
            cout << "incorrect\n";
        } else {
            cout << "correct\n";
        }
        while(!stk.empty()) {
            stk.pop();
        }
        flag = true;
    }

    return 0;

}