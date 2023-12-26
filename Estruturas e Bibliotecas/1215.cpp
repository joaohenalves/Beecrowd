#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    char c;
    string word;
    set<string> allWords;
    while(c = getchar_unlocked(), c != EOF) {
        c = tolower(c);
        if(c - 'a' >= 0 && c - 'a' <= 25) {
            word.push_back(c);
        } else {
            if(word.size() > 0) {
                allWords.emplace(word);
                word = "";
            }
        }
    }
    for(auto w : allWords) cout << w << "\n";
    return 0;
}
