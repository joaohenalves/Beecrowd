#include <bits/stdc++.h>
using namespace std;

#define MAX 11234
#define MAX_K 1123
typedef pair<int, int> ii;

vector<vector<int>> graph(MAX);
vector<vector<int>> camp(MAX_K);
int n, k, vis[MAX], line[MAX_K];

int bfs() {
    queue<ii> q;
    for(int &l : graph[0]) {
        line[l] = 1;
        q.emplace(1, l);
    }
    vis[0] = 1;
    while(!q.empty()) {
        auto [ld, lq] = q.front();
        q.pop();
        for(int &v : camp[lq]) {
            if(v == n - 1) return ld;
            if(vis[v] == 0) {
                for(int &l : graph[v]) {
                    if(line[l] == 0) {
                        q.emplace(ld + 1, l);
                        line[l] = 1;
                    }
                }
                vis[v] = 1;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l, u;
    memset(vis, 0, sizeof(vis));
    memset(line, 0, sizeof(line));
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> l;
        for(int j = 0; j < l; j++) {
            cin >> u;
            u--;
            graph[u].push_back(i);
            camp[i].push_back(u);
        }
    }
    cout << bfs() << "\n";
    return 0;
}
