#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef stack<int> st;


vvi graph;
vvi graphInv;
vi marked;
stack<int> ks;
unordered_map<int, int> scc;
vector<pair<int, int> > inAndOut;

void dfs(int v, vvi &gr, int flag, int id) {
    marked[v] = 1;
    for(int i = 0; i < gr[v].size(); i++) {
        if(marked[gr[v][i]] == 0) {
            dfs(gr[v][i], gr, flag, id);
        }
    }
    if(flag == 1) ks.push(v);
    else scc[v] = id;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m , v1, v2, temp, countIn = 0, countOut = 0, counter = 0;
    cin >> n >> m;
    graph.resize(n);
    graphInv.resize(n);
    marked.resize(n);
    inAndOut.resize(n);
    for(int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        v1--; v2--;
        graph[v1].push_back(v2);
        graphInv[v2].push_back(v1);
    }
    for(int j = 0; j < n; j++) {
        if(marked[j] == 0) {
            dfs(j, graph, 1, 0);
        }
    }
    fill(marked.begin(), marked.end(), 0);
    while(!ks.empty()) {
        temp = ks.top();
        ks.pop();
        if(marked[temp] == 0) {
            dfs(temp, graphInv, 0, counter);
            counter++;
        }
    }
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < graph[x].size(); y++) {
            if(scc[x] != scc[graph[x][y]]) {
                if(inAndOut[graph[x][y]].first == 0) {
                    countIn++;
                    inAndOut[graph[x][y]].first = 1;
                }
                if(inAndOut[x].second == 0) {
                    countOut++;
                    inAndOut[x].second = 1;
                }
            }
        }
    }
    cout << max(counter - countIn, counter - countOut) << "\n";
    return 0;
}
