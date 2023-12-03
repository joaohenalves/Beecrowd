/* Técnica bem interessante aqui utilizada, tomamos vantagem de que
o cavalo é uma peça que consegue chegar em qualquer casa do tabuleiro
e que o grafo é completo, portanto usamos a "simetria do tabuleiro", calculando
a bfs para somente metade dos vértices do grafo (talvez seja possível calcular somente para 1/8 do grafo). 
Por exemplo, a distância da casa a1 para a2 é a mesma distância da casa h8 para h7. */

#include <bits/stdc++.h>
using namespace std;

#define MAX 64

int dist[MAX][MAX];
int marked[MAX][MAX];
int mvx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int mvy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void bfs(int i, int j) {
    int ii, jj, src = i * 8 + j, aux = 7 * 8 + 7;
    pair<int, int> temp;
    queue<pair<int, int> > q;
    dist[src][src] = 0;
    dist[aux - src][aux - src] = 0;
    marked[src][src] = 1;
    q.emplace(i, j);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        for(int k = 0; k < 8; k++) {
            ii = temp.first + mvy[k];
            jj = temp.second + mvx[k];
            if(ii >= 0 && ii < 8 && jj >= 0 && jj < 8 && marked[src][ii * 8 + jj] == 0) {
                dist[src][ii * 8 + jj] = dist[src][temp.first * 8 + temp.second] + 1;
                dist[aux - src][aux - (ii * 8 + jj)] = dist[aux - src][aux - (temp.first * 8 + temp.second)] + 1;
                marked[src][ii * 8 + jj] = 1;
                q.emplace(ii, jj);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string src, dst;
    memset(marked, 0, sizeof(marked));
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j <= i; j++) {
            bfs(i, j);
        }
    }
    while(cin >> src >> dst) {
        int a = ((src[1] - '1') * 8) + src[0] - 'a';
        int b = ((dst[1] - '1') * 8) + dst[0] - 'a';
        cout << "To get from " << src << " to " << dst << " takes " << dist[a][b] << " knight moves.\n";
    }
    return 0;
}
