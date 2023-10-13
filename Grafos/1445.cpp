#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
bitset<1000> visited;

void depthFirstSearch(int vertex) {
    visited.set(vertex);
    for(auto edges : graph[vertex]) {
        if(!visited.test(edges)) {
            depthFirstSearch(edges);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string info, num1, num2;
    int n, numInt1, numInt2, maxS;
    bool numOne = true;
    vector<int> emptyEdgesList;
    for(;;) {
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++) {
            cin >> info;
            num1 = "";
            num2 = "";
            numOne = true;
            for(int j = 1; j < info.size() - 1; j++) {
                if(info[j] == ',') {
                    numOne = false;
                    continue;
                }
                if(numOne) num1.push_back(info[j]);
                else num2.push_back(info[j]);
            }
            numInt1 = stoi(num1);
            numInt2 = stoi(num2);
            maxS = graph.size();
            for(int k = 0; k < max(numInt1, numInt2) - maxS; k++) {
                graph.emplace_back(emptyEdgesList);
            }
            graph[numInt1 - 1].emplace_back(numInt2 - 1);
            graph[numInt2 - 1].emplace_back(numInt1 - 1);
        }
        depthFirstSearch(0);
        cout << visited.count() << "\n";
        for(auto clearGraph : graph) {
            clearGraph.clear();
        }
        graph.clear();
        visited.reset();
    }
    return 0;
}