#include <bits/stdc++.h>
using namespace std;

#define MAXV 21234

vector<vector<int> > graph(MAXV);
stack<int> stk;
int n, m, ord, counter, vis[MAXV], inEdge[MAXV], scc[MAXV], inStack[MAXV], cycle[MAXV];

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
    int u, v, s, countIn = 1;
    cin >> n >> m >> s;
    s--;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
    }
    memset(vis, 0, sizeof(vis));
    memset(inStack, 0, sizeof(inStack));
    ord = 1; counter = 0;
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) tarjan(i);
    }
    memset(inEdge, 0, sizeof(inEdge));
    for(u = 0; u < n; u++) {
        for(int &v : graph[u]) {
            if(scc[u] != scc[v] && inEdge[scc[v]] == 0 && scc[v] != scc[s]) {
                inEdge[scc[v]] = 1;
                countIn++;
            }
        }
    }
    cout << counter - countIn << "\n";
    return 0;
}
