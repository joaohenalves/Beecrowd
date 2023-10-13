#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, n;
    string str1, str2;
    map<string, string> word;
    cin >> k;
    getline(cin, str1);
    for(int i = 0; i < k; i++) {
        getline(cin, str1);
        getline(cin, str2);
        word[str1] = str2;
    }
    cin >> n;
    getline(cin, str1);
    for(int j = 0; j < n; j++) {
        getline(cin, str1);
        getline(cin, str2);
        cout << str1 << "\n" << word[str2] << "\n\n";
    }
    return 0;
}