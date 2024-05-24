#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
#define MOD 1000000007

vector<vector<int>> graph(MAX);
vector<vector<int>> dag(MAX);
int vis[MAX], cycle[MAX], scc[MAX], tsort[MAX], dp[MAX], inStack[MAX];
int n, m, s, t, ord, ts, counter;
stack<int> st;

void tarjan(int u, vector<vector<int>> &graph) {
    vis[u] = cycle[u] = ord++;
    st.push(u);
    inStack[u] = 1;
    for(int &v : graph[u]) {
        if(vis[v] == 0) tarjan(v, graph);
        if(inStack[v]) cycle[u] = min(cycle[u], cycle[v]);
    }
    if(vis[u] == cycle[u]) {
        int w;
        do {
            w = st.top();
            st.pop();
            inStack[w] = 0;
            scc[w] = counter;
        } while(w != u);
        counter++;
    }
}

void dfs(int u, vector<vector<int>> &graph) {
    vis[u] = 1;
    for(int &v : graph[u]) {
        if(vis[v] == 0) dfs(v, graph);
    }
    tsort[ts++] = u;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, u, v;
    cin >> n >> m >> s >> t;
    s--; t--;
    for(i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
    }
    ord = 1;
    counter = 0;
    memset(vis, 0, sizeof(vis));
    memset(inStack, 0, sizeof(inStack));
    for(u = 0; u < n; u++) {
        if(vis[u] == 0) tarjan(u, graph);
    }
    for(u = 0; u < n; u++) {
        for(int &v : graph[u]) {
            if(scc[u] != scc[v]) {
                dag[scc[u]].push_back(scc[v]);
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    ts = 0;
    for(u = 0; u < counter; u++) {
        if(vis[u] == 0) dfs(u, dag);
    }
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    dp[scc[s]] = 1;
    for(i = counter - 1; i >= 0; i--) {
        u = tsort[i];
        for(int &v : dag[u]) {
            if(!vis[v]) {
                dp[v] += dp[u];
                dp[v] %= MOD;
                vis[v] = 1;    
            }
        }
        for(int &v : dag[u]) vis[v] = 0;
    }
    cout << dp[scc[t]] << "\n";
    return 0;
}
