#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
vector<int> familyMembers;
bitset<1000> visitedConComp;
bitset<1000> visitedVertices;
int edgeCounter;
bool inconsistent = false;

void depthFirstSearch(int vertex) {
    visitedVertices.set(vertex);
    visitedConComp.set(vertex);
    edgeCounter += graph[vertex].size();
    for(auto edges : graph[vertex]) {
        if(!visitedVertices.test(edges)) {
            depthFirstSearch(edges);
        }
    }
}

void familyCounter(int n) {
    int visited;
    for (int v = 0; v < n; v++) {
        if (visitedConComp[v] == 0) {
            edgeCounter = 0;
            depthFirstSearch(v);
            visited = visitedVertices.count();
            familyMembers.emplace_back(visited);
            if(edgeCounter != visited*(visited - 1)) {
                inconsistent = true;
                return;
            }
            visitedVertices.reset();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string line;
    int n;
    vector<int> emptyEdgesList;
    cin >> n;
    for(int k = 0; k < n; k++) {
        graph.emplace_back(emptyEdgesList);
    }
    for(int i = 0; i < n; i++) {
        cin >> line;
        for(int j = i + 1; j < n; j++) {
            if(line[j] == 'S') {
                graph[i].emplace_back(j);
                graph[j].emplace_back(i);
            }
        }
    }
    familyCounter(n);
    if(inconsistent) {
        cout << -1 << "\n";
    } else {
        cout << familyMembers.size() << "\n";
        sort(familyMembers.rbegin(), familyMembers.rend());
        for(int z = 0; z < familyMembers.size(); z++) {
            cout << familyMembers[z];
            if(z < familyMembers.size() - 1) cout << " ";
            else cout << "\n";
        }
    }
    return 0;
}
