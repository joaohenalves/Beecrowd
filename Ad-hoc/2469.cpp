#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, temp, key;
    int max = 0;
    map<int, int> grades;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        grades[temp]++;
    }
    for(auto data : grades) {
        if(data.second >= max) {
            max = data.second;
            key = data.first;
        }
    }
    cout << key << "\n";
    return 0;
}