#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

vector<ii> num(10000);

bool comp(ii a, ii b) {
    if(a.first == b.first) {
        if(a.second & 1) {
            if((b.second & 1) == 0) return true;
            else return a.second > b.second;
        } else {
            if(b.second & 1) return false;
            else return a.second < b.second;
        }
    } else return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, v;
    while(cin >> n >> m) {
        cout << n << " " << m << "\n";
        if(!n) break;
        for(int i = 0; i < n; i++) {
            cin >> v;
            num[i] = {v % m, v};
        }
        sort(num.begin(), num.begin() + n, comp);
        for(int j = 0; j < n; j++) {
            cout << num[j].second << "\n";
        }
    }
    return 0;
}