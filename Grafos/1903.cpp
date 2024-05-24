#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

vector<vector<int>> graph(MAX);
vector<unordered_set<int>> newGraph(MAX);
stack<int> stk;
int n, m, idx, ord, counter, vis[MAX], scc[MAX], inStack[MAX], cycle[MAX], topoSort[MAX];

void dfs(int u) {
    vis[u] = 1;
    for(int v : newGraph[u]) {
        if(vis[v] == 0) dfs(v);
    }
    topoSort[idx++] = u;
}

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
    int i, u, v, flag = 0;
    cin >> n >> m;
    for(i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
    }
    memset(vis, 0, (n + 1) * sizeof(vis[0]));
    memset(inStack, 0, (n + 1) * sizeof(inStack[0]));
    ord = 1; counter = 0;
    for(i = 0; i < n; i++) {
        if(vis[i] == 0) tarjan(i);
    }
    for(i = 0; i < n; i++) {
        for(auto &v : graph[i]) {
            if(scc[i] != scc[v]) {
                newGraph[scc[i]].insert(scc[v]);
            }
        }
    }
    memset(vis, 0, (counter + 1) * sizeof(vis[0]));
    idx = 0;
    for(i = 0; i < counter; i++) {
        if(vis[i] == 0) {
            dfs(i);
        }
    }
    for(i = idx - 1; i > 0; i--) {
        if(newGraph[topoSort[i]].find(topoSort[i - 1]) == newGraph[topoSort[i]].end()) {
            flag = 1;
            break;
        }
    }
    cout << (flag ? "Nao Bolada" : "Bolada") << "\n";
    return 0;
}
