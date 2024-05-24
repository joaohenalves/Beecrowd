#include <bits/stdc++.h>
using namespace std;

#define MAX 27

int dist[MAX][MAX];

void floydWarshall() {
    int i, j, k;
    for(k = 0; k < MAX; k++) {
        for(i = 0; i < MAX; i++) {
            for(j = 0; j < MAX; j++) {
                dist[i][j] |= dist[i][k] & dist[k][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, j, n, m, flag;
    string s1, s2;
    char a, b;
    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++) {
            dist[i][j] = i == j ? 1 : 0;
        }
    }
    cin >> m >> n;
    for(i = 0; i < m; i++) {
        cin >> a >> b;
        dist[a - 'a'][b - 'a'] = 1;
    }
    floydWarshall();
    for(i = 0; i < n; i++) {
        flag = 0;
        cin >> s1 >> s2;
        if(s1.size() != s2.size()) flag = 1;
        else {
            for(j = 0; j < s1.size(); j++) {
                if(dist[s1[j] - 'a'][s2[j] - 'a'] == 0) {
                    flag = 1;
                    break;
                }
            }
        }
        cout << (flag ? "no" : "yes") << "\n";
    }
    return 0;
}
