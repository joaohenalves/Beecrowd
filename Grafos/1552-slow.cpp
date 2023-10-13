#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double>  pdd;

double prim(vector<vector<pdd> > &graph) {
    bitset<500> onTree;
    int counter = 1;
    double mst = 0;
    pdd temp;
    priority_queue<pdd, vector<pdd>, greater<pdd> > pq;
    for(auto edges : graph[0]) {
        pq.emplace(edges.second, edges.first);
        onTree[0] = 1;
    }
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
    int n, p;
    double x, y, dist;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p;
        vector<pdd> crd; 
        crd.reserve(p);
        vector<vector<pdd> > graph(p);
        for(int j = 0; j < p; j++) {
            cin >> x >> y;
            crd.emplace_back(x, y);
        }
        for(int k = 0; k < p; k++) {
            for(int l = k + 1; l < p; l++) {
                dist = sqrt(pow(crd[k].first - crd[l].first, 2) + pow(crd[k].second - crd[l].second, 2));
                graph[k].emplace_back(l, dist);
                graph[l].emplace_back(k, dist);
            }
        }
        cout << fixed;
        cout.precision(2);
        cout << round(prim(graph)) / 100 << "\n";
        for(int m = 0; m < p; m++) {
            graph[m].clear();
        }
        graph.clear();
    }
    return 0;
}