#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
bitset<50> onTree;

int prim(vector<vector<pii> > &graph, int start) {
    int mst = 0;
    pii temp;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(auto edges : graph[start]) {
        pq.emplace(edges.second, edges.first);
    }
    onTree[start] = 1;
    int counter = 1;
    while(!pq.empty()) {
        temp = pq.top();
        pq.pop();
        if(onTree[temp.second] == 0) {
            onTree[temp.second] = 1;
            counter++;
            mst += temp.first;
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
    int c, n, m, start, v1, v2;
    cin >> c;
    while(c--) {
        cin >> start >> n >> m;
        vector<vector<pair<int, int> > > graph(n);
        onTree.reset();
        for(int i = 0; i < m; i++) {
            cin >> v1 >> v2;
            graph[v1].emplace_back(v2, 1);
            graph[v2].emplace_back(v1, 1);
        }
        cout << prim(graph, start) * 2 << "\n";
    }
    return 0;
}