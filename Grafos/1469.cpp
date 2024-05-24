#include <bits/stdc++.h>
using namespace std;


vector<pair<int, vector<int> > > graph;
bitset<500> visited;
int minAge;
const int INF = 9999999;
bool firstTest;

void depthFirstSearch(int vertex) {
    visited.set(vertex);
    if(graph[vertex].first < minAge && firstTest) minAge = graph[vertex].first;
    firstTest = true;
    for(auto edges : graph[vertex].second) {
        if(!visited.test(edges)) {
            depthFirstSearch(edges);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string op;
    int vertices, edges, instructions, temp1, temp2;
    vector<int> emptyEdgesList;
    while(cin >> vertices >> edges >> instructions) {
        vector<int> employees (vertices);
        graph.reserve(vertices);
        for(int i = 0; i < vertices; i++) {
            cin >> temp1;
            graph.emplace_back(temp1, emptyEdgesList);
            employees[i] = i;
        }
        for(int j = 0; j < edges; j++) {
            cin >> temp1 >> temp2;
            graph[temp2 - 1].second.emplace_back(temp1 - 1);
        }
        for(int k = 0; k < instructions; k++) {
            cin >> op;
            if(op == "P") {
                cin >> temp1;
                minAge = INF;
                firstTest = false;
                depthFirstSearch(employees[temp1 - 1]);
                visited.reset();
                if(minAge != INF) cout << minAge << "\n";
                else cout << "*\n";
            } else if(op == "T") {
                cin >> temp1 >> temp2;
                swap(employees[temp1 - 1], employees[temp2 - 1]);
                swap(graph[employees[temp1 - 1]].first, graph[employees[temp2 - 1]].first);
            }
        }
        for(auto clearGraph : graph) {
            clearGraph.second.clear();
        }
        graph.clear();
        employees.clear();
    }
    return 0;
}
