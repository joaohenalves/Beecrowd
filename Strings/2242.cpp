#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char vowels[5] = {'a','e','i','o','u'};
    string str;
    string vowelStr;
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        bool flag = false;
        for(int j = 0; j < 5; j++) {
            if(str[i] == vowels[j]) {
                flag = true;
            }
        }
        if(flag) {
            vowelStr.push_back(str[i]);
        }
    }
    bool result = true;
    for(int k = 0; k < vowelStr.size(); k++) {
        if(vowelStr[k] != vowelStr[vowelStr.size() - 1 - k]) {
            result = false;
            break;
        }
    }
    cout << (result ? "S\n" : "N\n");

    return 0;
}