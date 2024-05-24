#include <bits/stdc++.h>
using namespace std;

#define MAX 1123

int n, graph[MAX];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, u, v, x = 1;
    cin >> n >> m;
    memset(graph, 0, sizeof(graph));
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u]++;
        graph[v]++;
    }
    for(int i = 0; i < n; i++) {
        x &= !(graph[i] & 1);
    }
    cout << (x ? "Rambo esta salvo" : "Rambo esta perdido") << "\n";
    return 0;
}
