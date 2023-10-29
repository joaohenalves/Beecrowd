#include <bits/stdc++.h>
using namespace std;

int s, l, w, currentLine, lines, pages;

void check(const string &word) {
    if(currentLine >= word.size()) {
        currentLine -= word.size();
    } else if(word != " "){
        lines++;
        currentLine = s - word.size();
        if(lines == l) {
            lines = 0;
            pages++;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string word;
    while(cin >> w >> l >> s) {
        currentLine = s;
        lines = 0;
        pages = 0;
        for(int i = 0; i < w; i++) {
            cin >> word;
            check(word);
            if(i != w - 1) check(" ");
        }
        cout << pages + (lines || (currentLine < s) ? 1 : 0) << "\n";
    }
    return 0;
}
