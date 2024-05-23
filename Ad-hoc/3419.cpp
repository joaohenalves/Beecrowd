#include <bits/stdc++.h>
using namespace std;
 
#define MAX 112
#define INF 112345678
typedef pair<int, int> ii;

int col[MAX];
vector<ii> vet(MAX);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, v, np, id, temp, nv, fl = INF;
    string s, aux;
    cin >> n >> v;
    for(int i = 0; i < n; i++) {
        cin >> np;
        vet[i].second = np;
        for(int j = 0; j < v; j++) {
            cin >> s;
            aux = "";
            for(auto c : s) {
                if(c != ':') aux.push_back(c);
            }
            temp = stoi(aux);
            if(temp < fl) {
                fl = temp;
                id = np;
                nv = vet[i].first;
            } else if(temp == fl) {
                if(vet[i].first < nv) {
                    id = np;
                    nv = j;
                }
            }
            vet[i].first += temp;
        }
    }
    sort(vet.begin(), vet.begin() + n);
    for(int i = 0; i < n; i++) {
        col[vet[i].second] = i;
    }
    if(col[id] <= 9) cout << id << "\n";
    else cout << "NENHUM\n";
    return 0;
}
