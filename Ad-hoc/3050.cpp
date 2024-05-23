#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
typedef long long ll;

ll memo[MAX], l[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll dist1, dist2, maxDist;
    cin >> n;
    memo[0] = -1;
    for(int i = 0; i < n; i++) {
        cin >> l[i];
        if(i == 1) {
            memo[i] = 0;
            maxDist = l[i] + l[0] + 1;
        } else if(i > 1) {
            dist1 = l[i] + l[i - 1] + 1;
            dist2 = l[i] + l[memo[i - 1]] + (i - memo[i - 1]);
            memo[i] = (dist1 >= dist2 ? i - 1 : memo[i - 1]);
            maxDist = max(maxDist, max(dist1, dist2));
        }
    }
    cout << maxDist << "\n";
    return 0;
}
