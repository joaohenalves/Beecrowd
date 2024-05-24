#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

vector<vector<int>> graph(MAX);
stack<int> stk;
int n, m, ord, counter, vis[MAX], inStack[MAX], cycle[MAX];

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
        } while(w != u);
        counter++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, u, v;
    cin >> n ;
    for(i = 0; i < n; i++) {
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
    }
    memset(vis, 0, (n + 1) * sizeof(vis[0]));
    memset(inStack, 0, (n + 1) * sizeof(inStack[0]));
    ord = 1; counter = 0;
    for(i = 0; i < n; i++) {
        if(vis[i] == 0) {
            if(counter == 1) {
                counter++;
                break;
            } else tarjan(i);
        }
    }
    cout << (counter == 1 ? 'S' : 'N') << "\n";
    return 0;
}
