#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

int o, d, vis[MAX];

inline bool valid(int n) {
    return(n > 0 && n <= 100000 && vis[n] == 0);
}

int bfs() {
    queue<int> q;
    int x;
    q.emplace(o);
    while(!q.empty()) {
        x = q.front();
        q.pop();
        if(valid(x + 1)) {
            vis[x + 1] = vis[x] + 1;
            q.emplace(x + 1);
            if(x + 1 == d) return vis[x + 1];
        }
        if(valid(x - 1)) {
            vis[x - 1] = vis[x] + 1;
            q.emplace(x - 1);
            if(x - 1 == d) return vis[x - 1];
        }
        if(valid(x * 2)) {
            vis[x * 2] = vis[x] + 1;
            q.emplace(x * 2);
            if(x * 2 == d) return vis[x * 2];
        }
        if(valid(x * 3)) {
            vis[x * 3] = vis[x] + 1;
            q.emplace(x * 3);
            if(x * 3 == d) return vis[x * 3];
        }
        if((x & 1) == 0 && valid(x / 2)) {
            vis[x / 2] = vis[x] + 1;
            q.emplace(x / 2);
            if(x / 2 == d) return vis[x / 2];
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int s, aux;
    while(cin >> o >> d >> s, o) {
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < s; i++) {
            cin >> aux;
            vis[aux] = 1;
        }
        cout << bfs() << "\n";
    }
    return 0;
}
