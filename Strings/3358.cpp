#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, streak;
    string s;
    char c;
    cin >> n;
    while(n--) {
        cin >> s;
        streak = 0;
        for(int i = 0; i < s.size(); i++) {
            c = tolower(s[i]);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                streak = 0;
            } else streak++;
            if(streak == 3) break;
        }
        cout << s << (streak == 3 ? " nao" : "") << " eh facil\n";
    }
    return 0;
}
