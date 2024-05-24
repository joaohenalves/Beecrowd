//verifica se uma lista de graus de vértices de um grafo não dirigido forma um grafo


#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
typedef long long ll;

int deg[MAX], rng[MAX];
ll l[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, flag;
    ll total;
    while(cin >> n) {
        total = 0;
        for(int i = 1; i <= n; i++) {
            cin >> deg[i];
            total += deg[i];
        }
        if((total & 1) == 0) {
            flag = 0;
            sort(deg + 1, deg + n + 1, greater<int>());
            l[0] = 0;
            for(int i = 1; i <= n; i++) {
                l[i] = deg[i] + l[i - 1];
            }
            l[n + 1] = l[n];
            x = n;
            for(int i = 1; i <= n; i++) {
                while(deg[x] < i) x--;
                rng[i] = max(x, i);
            }
            for(int k = 1; k <= n; k++) {
                ll y = (ll) (rng[k] - k) * k + l[n] - l[rng[k]];
                if(l[k] > (ll) k * (k - 1) + y) {
                    flag = 1;
                    break;
                }
            }
        } else flag = 1;
        cout << (flag == 0 ? "possivel" : "impossivel") << "\n";
    }
    return 0;
}
