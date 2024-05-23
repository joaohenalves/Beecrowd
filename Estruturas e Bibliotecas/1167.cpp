#include <bits/stdc++.h>
using namespace std;

#define MAX 112

vector<string> name(MAX);
int l[MAX];
bool alive[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, c, idx, ans, z;
    while(cin >> n, n) {
        c = n;
        memset(alive, 1, sizeof(alive));
        for(int i = 0; i < n; i++) {
            cin >> name[i] >> l[i];
        }
        idx = 0;
        while(c > 1) {
            z = l[idx];
            if((z & 1) == 0) {
                idx = idx > 0 ? idx - 1 : n - 1;
                while(z > 0) {
                    if(alive[idx]) z--;
                    if(z > 0) idx--;
                    if(idx < 0) idx = n - 1;
                }
                c--;
                alive[idx] = 0;
            } else {
                idx = idx < n - 1 ? idx + 1 : 0;
                while(z > 0) {
                    if(alive[idx]) z--;
                    if(z > 0) idx++;
                    if(idx >= n) idx = 0;
                }
                c--;
                alive[idx] = 0;
            }
        }
        for(int i = 0; i < n; i++) {
            if(alive[i]) cout << "Vencedor(a): " << name[i] << "\n";
        }
    }
    return 0;
}
