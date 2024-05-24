#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int> ii;

int marked[112345];
int n, m;

int bfs() {
    queue<ii> q;
    ii temp;
    int rev;
    memset(marked, 0, sizeof(marked));
    marked[n] = 1;
    q.emplace(n, 0);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        if(marked[temp.first + 1] == 0) {
            if(temp.first + 1 == m) return temp.second + 1;
            marked[temp.first + 1] = 1;
            q.emplace(temp.first + 1, temp.second + 1);
        }
        rev = 0;
        while (temp.first > 0) { 
            rev = rev * 10 + temp.first % 10; 
            temp.first = temp.first / 10; 
        }
        if(marked[rev] == 0) {
            if(rev == m) return temp.second + 1;
            marked[rev] = 1;
            q.emplace(rev, temp.second + 1);
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << bfs() << "\n";
    }
    return 0;
}
