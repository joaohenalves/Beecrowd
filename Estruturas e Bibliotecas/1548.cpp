#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b) { return a > b; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, c, counter;
    vector<int> grades1(1123);
    vector<int> grades2(1123);
    cin >> c;
    while(c--) {
        cin >> n;
        counter = 0;
        for(int i = 0; i < n; i++) {
            cin >> grades1[i];
            grades2[i] = grades1[i];
        }
        sort(grades1.begin(), grades1.begin() + n, comp);
        for(int j = 0; j < n; j++) {
            if(grades1[j] == grades2[j]) counter++;
        }
        cout << counter << "\n";
    }
    return 0;
}
