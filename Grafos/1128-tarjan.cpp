#include <bits/stdc++.h>
using namespace std;

#define MAXV 2123

vector<vector<int> > graph(MAXV);
stack<int> stk;
int n, m, ord, counter, vis[MAXV], scc[MAXV], inStack[MAXV], cycle[MAXV];

void tarjan(int u) {
    vis[u] = cycle[u] = ord++;
    stk.push(u);
    inStack[u] = 1;
    for(int &v : graph[u]) {
        if(vis[v] == 0) tarjan(v);
        if(inStack[v]) cycle[u] = min(cycle[u], cycle[v]);
    }
    if(vis[u] == cycle[u]) {
        int w;
        do {
            w = stk.top();
            stk.pop();
            inStack[w] = 0;
            scc[w] = counter;
        } while(w != u);
        counter++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v, p;
    while(cin >> n >> m, n) {
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> p;
            u--; v--;
            graph[u].push_back(v);
            if(p == 2) graph[v].push_back(u);
        }
        memset(vis, 0, sizeof(vis));
        memset(inStack, 0, sizeof(inStack));
        ord = 1; counter = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                if(counter == 1) {
                    counter++;
                    break;
                } else tarjan(i);
            }
        }
        for(int i = 0; i < n; i++) graph[i].clear();
        cout << (counter == 1 ? 1 : 0) << "\n";
    }
    return 0;
}
