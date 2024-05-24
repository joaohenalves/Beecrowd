#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef stack<int> st;

vvi graph(2123);
vvi graphInv(2123);
vi marked(2123);
stack<int> ks;

void dfs(int v, vvi &gr, int flag) {
    marked[v] = 1;
    for(int i = 0; i < gr[v].size(); i++) {
        if(marked[gr[v][i]] == 0) {
            dfs(gr[v][i], gr, flag);
        }
    }
    if(flag == 1) ks.push(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m , u, v, cond, temp, counter;
    while(cin >> n >> m, n) {
        counter = 0;
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> cond;
            u--; v--;
            graph[u].push_back(v);
            graphInv[v].push_back(u);
            if(cond == 2) {
                graph[v].push_back(u);
                graphInv[u].push_back(v);
            }
        }
        for(int j = 0; j < n; j++) {
            if(marked[j] == 0) {
                dfs(j, graph, 1);
            }
        }
        fill(marked.begin(), marked.begin() + n, 0);
        while(!ks.empty()) {
            temp = ks.top();
            ks.pop();
            if(marked[temp] == 0) {
                if(counter == 1) { counter++; break; }
                dfs(temp, graphInv, 0);
                counter++;
            }
        }
        cout << (counter == 2 ? 0 : 1) << "\n";
        while(!ks.empty()) ks.pop();
        for(int i = 0; i < n; i++) {
            graph[i].clear();
            graphInv[i].clear();
            marked[i] = 0;
        }
    }
    return 0;
}
