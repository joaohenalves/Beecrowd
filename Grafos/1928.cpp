#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

#define MAX 212345
#define left(p) ((p) << 1)
#define right(p) (left(p) + 1)

int n;
int lvl[MAX], trail[MAX], tsize, first[MAX];
int st[4 * MAX];

int build_st(int p, int l, int r) {
  int mid = (l + r) / 2, p1, p2;
  if (l == r) return st[p] = l;
  p1 = build_st(left(p), l, mid);
  p2 = build_st(right(p), mid + 1, r);
  return st[p] = lvl[trail[p1]] <= lvl[trail[p2]] ? p1 : p2;
}

int rmq(int p, int l, int r, int i, int j) {
  int mid = (l + r) / 2, p1, p2;
  if (j < l || r < i) return -1;
  if (i <= l && r <= j) return st[p];
  p1 = rmq(left(p), l, mid, i, j);
  p2 = rmq(right(p), mid + 1, r, i, j);
  if (p1 == -1) return p2;
  if (p2 == -1) return p1;
  return lvl[trail[p1]] <= lvl[trail[p2]] ? p1 : p2;
}

int lca(int u, int v) {
  int i = first[u], j = first[v];
  if (i > j) return lca(v, u);
  return trail[rmq(1, 0, tsize - 1, i, j)];
}

void dfs(int u, int l, vector<vi> &lg) {
  int i, v;
  lvl[u] = l; first[u] = tsize; trail[tsize++] = u;
  for (i = 0; i < (int)lg[u].size(); i++) {
    v = lg[u][i];
    if (lvl[v] == -1) {
      dfs(v, l + 1, lg);
      trail[tsize++] = u;
    }}}

int main(void) {
  int x, u, v, w, i;
  long long ans = 0;
  scanf("%d", &n);
  vector<ii> card(n / 2, ii(-1, -1));
  vector<vi> lg(n);
  for (u = 0; u < n; u++) {
    scanf("%d", &x); x--;
    if (card[x].first == -1) card[x].first = u;
    else card[x].second = u;
  }
  for (i = 1; i <= n - 1; i++) {
    scanf("%d %d", &u, &v); u--; v--;
    lg[u].push_back(v); lg[v].push_back(u);
  }
  memset(lvl, -1, sizeof(lvl));
  tsize = 0;
  dfs(0, 0, lg);
  build_st(1, 0, tsize - 1);
  for (x = 0; x <= n / 2 - 1; x++) {
    u = card[x].first; v = card[x].second;
    w = lca(u, v);
    ans += lvl[u] + lvl[v] - 2 * lvl[w];
  }
  printf("%lld\n", ans);
  return 0;
}
