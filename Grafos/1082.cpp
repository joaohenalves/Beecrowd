#include <bits/stdc++.h>
using namespace std;


vector<vector<int> > graph;
vector<int> result;
bitset<26> visited;

void dfs(int vertex) {
    visited.set(vertex);
    result.emplace_back(vertex);
    for(auto data : graph[vertex]) {
        if(!visited.test(data)) {
            dfs(data);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> emptyList;
    int cases = 1;
    int n, edges, vertices, counter;
    char ver1, ver2;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> vertices >> edges;
        graph.reserve(vertices);
        for(int k = 0; k < vertices; k++) {
            graph.emplace_back(emptyList);
        }
        for(int j = 0; j < edges; j++) {
            cin >> ver1 >> ver2;
            graph[((int) ver1) - 97].emplace_back(((int) ver2) - 97);
            graph[((int) ver2) - 97].emplace_back(((int) ver1) - 97);
        }
        counter = 0;
        cout << "Case #" << cases << ":\n";
        for(int v = 0; v < graph.size(); v++) {
            if(!visited.test(v)) {
                result.clear();
                dfs(v);
                counter++;
                sort(result.begin(), result.end());
                for(auto r : result) {
                    cout << static_cast<char>(r + 97) << ',';
                }
                cout << "\n";
            }
        }
        cout << counter << " connected components\n\n";
        for(int l = 0; l < graph.size(); l++) {
            graph[l].clear();
        }
        graph.clear();
        visited.reset();
        cases++;
    }
    return 0;
}
