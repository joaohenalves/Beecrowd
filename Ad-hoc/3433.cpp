#include <bits/stdc++.h>
using namespace std;
 
#define MAX 1123456
#define INF 112345678
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m1, m2, j1, j2, c, m, j, flag, w, mx, cards[15];
    memset(cards, 0, sizeof(cards));
    cin >> n;
    cin >> j1 >> j2;
    cards[j1]++; cards[j2]++;
    j = min(j1, 10) + min(j2, 10);
    cin >> m1 >> m2;
    cards[m1]++; cards[m2]++;
    m = min(m1, 10) + min(m2, 10);
    for(int i = 0; i < n; i++) {
        cin >> c;
        c = min(c, 10);
        cards[c]++;
        j += c;
        m += c;
    }
    if(m < 13 && j < 13) cout << -1 << "\n";
    else if(m == j) {
        if(m != 13) cout << (cards[23 - m] < 4 ? 23 - m : -1) << "\n";
        else {
            flag = 0;
            for(int i = 10; i <= 13; i++) {
                if(cards[i] < 4) {
                    w = i;
                    flag = 1;
                    break;
                }
            }
            cout << (flag ? w : -1) << "\n";
        }
    } else if(j == 13 && m < j) cout << -1 << "\n";
    else if(m == 13 && j < m) {
        flag = 0;
        for(int i = 10; i <= 13; i++) {
            if(cards[i] < 4) {
                w = i;
                flag = 1;
                break;
            }
        }
        cout << (flag ? w : -1) << "\n";
    } else {
        if(j > m) {
            flag = 0;
            mx = 23 - m;
            for(int i = 23 - j + 1; i <= mx; i++) {
                if(cards[i] < 4) {
                    w = i;
                    flag = 1;
                    break;
                }
            }
            cout << (flag ? w : -1) << "\n";
        } else cout << (cards[23 - m] < 4 ? 23 - m : -1) << "\n";
    }
    return 0;
}
