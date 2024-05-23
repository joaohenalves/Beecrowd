#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int sum, ans;
    while(getline(cin, s)) {
        ans = sum = 0;
        for(char c : s) {
            if(c != ' ') sum += 1 + (c - (c < 'a' ? 'A' : 'a')) % 9;
        }
        while(sum > 10) {
            ans = 0;
            while(sum) {
                ans += sum % 10;
                sum /= 10;
            }
            sum = ans;
        }
        cout << (ans % 9 == 0 ? 9 : ans % 9) << "\n";
    }
    return 0;
}
