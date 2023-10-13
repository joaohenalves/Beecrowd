#include <bits/stdc++.h>
using namespace std;

unordered_map<string, pair<bool, vector<string> > > graph;

void dfs(string name) {
    graph[name].first = true;
    for(auto v : graph[name].second) {
        if(!graph[v].first) {
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string name1, r, name2;
    int n, m;
    int counter = 0;
    vector<string> emptyList;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> name1 >> r >> name2;
        graph[name1].first = false;
        graph[name1].second.emplace_back(name2);
        graph[name2].first = false;
        graph[name2].second.emplace_back(name1);
    }
    for(auto v : graph) {
        if(!v.second.first) {
            dfs(v.first);
            counter++;
        }
    }
    cout << counter << "\n";
    return 0;
}