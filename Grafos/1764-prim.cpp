#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
bitset<41234> onTree;

int prim(vector<vector<pii> > &graph) {
    int mst = 0;
    pii temp;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(auto edges : graph[0]) {
        pq.emplace(edges.second, edges.first);
    }
    onTree[0] = 1;
    int counter = 1;
    while(!pq.empty()) {
        temp = pq.top();
        pq.pop();
        if(onTree[temp.second] == 0) {
            onTree[temp.second] = 1;
            counter++;
            mst += temp.first;
            if(counter == graph.size()) break;
            for(auto edg : graph[temp.second]) {
                if(onTree[edg.first] == 0) {
                    pq.emplace(edg.second, edg.first);
                }
            }
        }
    }
    return mst;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int v1, v2, cost;
    int n, m;
    while(cin >> n >> m, n != 0) {
        vector<vector<pii>> graph(n);
        for (int j = 0; j < m; j++) {
            cin >> v1 >> v2 >> cost;
            graph[v1].emplace_back(v2, cost);
            graph[v2].emplace_back(v1, cost);
        }
        cout << prim(graph) << "\n";
        onTree.reset();
    }
    return 0;
}

