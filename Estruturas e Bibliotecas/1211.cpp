#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, counter, s;
    vector<string> telList(112345);
    while(cin >> n) {
        counter = 0;
        for(int k = 0; k < n; k++) cin >> telList[k];
        sort(telList.begin(), telList.begin() + n);
        int s = telList[0].size();
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < s; j++) {
                if(telList[i - 1][j] == telList[i][j]) counter++;
                else break;
            }
        }
        cout << counter << "\n";
    }
    return 0;
}