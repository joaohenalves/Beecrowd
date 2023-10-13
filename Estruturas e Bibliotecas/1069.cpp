#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string input;
    cin >> n;
    getline(cin, input);
    for(int i = 0; i < n; i++) {
        stack<int> s;
        int diamonds = 0;
        getline(cin, input);
        for(int j = 0; j < input.size(); j++) {
            if (input[j] == '<')
                s.push('<');
            if (input[j] == '>' && !s.empty()) {
                s.pop();
                diamonds++;
            }
        }
        cout << diamonds << '\n';
    }
    return 0;
}