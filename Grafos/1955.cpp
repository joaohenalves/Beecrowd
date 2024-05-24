#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph(1123);
vector<int> marked(1123, -1);
int n, m, color = 0;

int dfs(int v, int c) {
    marked[v] = c;
    for(const auto &u : graph[v]) {
        if(marked[u] == c) return 1;
        else if(marked[u] == -1) {
            if(dfs(u, c ^ 1)) return 1;
        }
    }
    return 0;
}


int colorGraph() {
    for(int i = 0; i < n; i++) {
        if(marked[i] == -1) {
            if(dfs(i, 0)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> m;
            if(m == 0) {
                graph[i].push_back(j);
            }
        }
    }
    cout << (colorGraph() ? "Fail!" : "Bazinga!") << "\n";
    return 0;
}
