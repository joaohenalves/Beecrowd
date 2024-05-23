#include <bits/stdc++.h>
using namespace std;

#define MAX 51234

int n, m, rain[MAX], g[2][MAX], remap[MAX];
unordered_map<int, int> mapping;

void calcGreater(int s, int f, int i, int l) {
    stack<int> stk;
    stk.push(s);
    s += i;
    while(s != f) {
        if(rain[s] < rain[stk.top()]) {
            stk.push(s);
        } else {
            while(!stk.empty() && rain[stk.top()] <= rain[s]) {
                g[l][stk.top()] = s;
                stk.pop();
            }
            stk.push(s);
        }
        s += i;
    }
    while(!stk.empty()) {
        g[l][stk.top()] = stk.top();
        stk.pop();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int y, x, r, id, diff, flag = 0, ans = 0;
    while(cin >> n) {
        if(n == 0) { cin >> m; break; }
        if(flag == 1) cout << "\n";
        flag = 1;
        id = 0;
        mapping.clear();
        for(int i = 0; i < n; i++) {
            cin >> y >> r;
            remap[id] = y;
            mapping[y] = id++;
            rain[mapping[y]] = r;
        }
        calcGreater(n - 1, -1, -1, 0);
        calcGreater(0, n, 1, 1);
        cin >> m;
        while(m--) {
            cin >> y >> x;
            if(mapping.find(y) == mapping.end()) {
                if(mapping.find(x) != mapping.end()) {
                    if(g[0][mapping[x]] != mapping[x] && remap[g[0][mapping[x]]] > y) ans = 2;
                    else ans = 1;
                } else ans = 1;
            } else {
                if(mapping.find(x) != mapping.end()) {
                    if((x < 0 && y < 0) || x >= 0 && y >= 0) diff = abs(x - y);
                    else diff = x + abs(y);
                    if(diff == mapping[x] - mapping[y]) {
                        if(g[0][mapping[x]] == mapping[y]) ans = 0;
                        else ans = 2;
                    } else {
                        if(g[0][mapping[x]] == mapping[y]) ans = 1;
                        else ans = 2;
                    }
                } else {
                    if(g[1][mapping[y]] != mapping[y] && remap[g[1][mapping[y]]] < x) ans = 2;
                    else ans = 1;
                }
            }
            if(ans == 0) cout << "true\n";
            if(ans == 1) cout << "maybe\n";
            if(ans == 2) cout << "false\n";
        }
    }
    return 0;
}
