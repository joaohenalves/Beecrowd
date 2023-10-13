#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, num, res, total;
    char ft;
    while(cin >> n) {
        map<int, pair<int, int> > boots;
        total = 0;
        while(n--) {
            cin >> num >> ft;
            if(ft == 'D') boots[num].first++;
            else boots[num].second++;
        }
        for(auto b : boots) {
            res = min(b.second.first, b.second.second);
            if(res) total += res;
        }
        cout << total << "\n";
    }

    return 0;
}