#include <bits/stdc++.h>

using namespace std;


void placeFront(deque<char> &text, basic_string<char> &partialText) {
    reverse(partialText.begin(), partialText.end());

    for (auto ch : partialText) {
        text.push_front(ch);
    }
    partialText.clear();
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<char> text;
    basic_string<char> partialText;
    string brokenText;

    while(cin >> brokenText) {
        bool front = false;
        for (auto c : brokenText) {
            if (c == '[') {
                front = true;
                if (partialText.size() > 0) {
                    placeFront(text, partialText);
                }
            }
            else if (c == ']') {
                front = false;
                placeFront(text, partialText);

            } else if (front) partialText.push_back(c);
            else text.push_back(c);
        }
        if (partialText.size() > 0) {
            placeFront(text, partialText);
        }

        for (auto c: text) cout << c;
        cout << "\n";

        text.clear(); partialText.clear();
    }
}
