#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

vector<int> counting1[MAX];
int n, k, tree[MAX], depth[MAX], marked[MAX], l[MAX], counting2[MAX];

void countingSortDepth() {
    for(int i = 0; i < n; i++) {
        counting1[depth[i]].push_back(i);
    }
}

void countingSort(int len) {
    int idx = 0;
    memset(counting2, 0, (n + 1) * sizeof(counting2[0]));
    for(int i = 0; i < len; i++) {
        counting2[l[i]]++;
    }
}

int dfs(int u) {
    marked[u] = 1;
    if(marked[tree[u]] == 0) return 1 + dfs(tree[u]);
    else return 1;
}

int findDepth(int u) {
    if(depth[u] != -1) return depth[u];
    return depth[u] = 1 + findDepth(tree[u]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, ans = 0, idx = 0;
    cin >> n >> k;
    memset(depth, -1, (n + 1) * sizeof(depth[0]));
    for(int i = 1; i < n; i++) {
        cin >> u;
        u--;
        tree[i] = u;
    }
    tree[0] = depth[0] = 0;
    for(int i = 0; i < n; i++) findDepth(i);
    countingSortDepth();
    memset(marked, 0, (n + 1) * sizeof(marked[0]));
    for(int i = n; i >= 0; i--) {
        for(int &j : counting1[i]) {
            l[idx++] = dfs(j);
        }
    }
    countingSort(idx);
    for(int i = n; i >= 0; i--) {
        for(int j = 0; j < counting2[i] && k; j++) {
            if(k) {
                ans += i;
                k--;
            } else break;
        }
    }
    cout << ans << "\n";
    return 0;
}
