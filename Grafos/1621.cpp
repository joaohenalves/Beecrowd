#include <bits/stdc++.h>
using namespace std;


#define INF 1e8
typedef pair<int, int> ii;

vector<string> grid(512);
int n, m, marked[512][512], dist[512][512];
int mi[] = {-1, 1, 0, 0};
int mj[] = {0, 0, 1, -1};

ii bfs(int i, int j) {
    queue<ii> q;
    ii temp, maxVertex;
    int ai, aj, maxDist = 0;
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            dist[y][x] = INF;
            marked[y][x] = 0;
        }
    }
    dist[i][j] = 0;
    marked[i][j] = 1;
    q.emplace(i, j);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        if(dist[temp.first][temp.second] > maxDist) {
            maxDist = dist[temp.first][temp.second];
            maxVertex = temp;
        }
        for(int k = 0; k < 4; k++) {
            ai = temp.first + mi[k];
            aj = temp.second + mj[k];
            if(ai >= 0 && ai < n && aj >= 0 && aj < m && grid[ai][aj] == '.' && marked[ai][aj] == 0) {
                marked[ai][aj] = 1;
                dist[ai][aj] = dist[temp.first][temp.second] + 1;
                q.emplace(ai, aj);
            }
        }
    }
    return maxVertex;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int flag;
    ii ans;
    while(cin >> n >> m, n) {
        flag = 0;
        for(int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        for(int i = 0; i < n && !flag; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '.') {
                    ans = bfs(i, j);
                    flag = 1;
                    break;
                }
            }
        }
        ans = bfs(ans.first, ans.second);
        cout << dist[ans.first][ans.second] << "\n";
    }
    return 0;
}
