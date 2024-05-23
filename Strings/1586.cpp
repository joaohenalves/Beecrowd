#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
typedef long long ll;
typedef pair<int, ll> ill;

vector<string> s(MAX);
int n;

ll check(int idx) {
    int i;
    ll aux, a = 0, b = 0; 
    for(i = idx; i >= 0; i--) {
        aux = 0;
        for(char &c : s[i]) aux += c;
        a += (ll)(idx - i + 1) * aux;
    }
    for(i = idx + 1; i < n; i++) {
        aux = 0;
        for(char &c : s[i]) aux += c;
        b += (ll)(i - idx) * aux;
    }
    return a - b;
}

ill binSearch() {
    int mid, inf = 0, sup = n - 1;
    ll aux;
    while(inf < sup) {
        mid = inf + (sup - inf) / 2;
        aux = check(mid);
        if(aux < 0) inf = mid + 1;
        else sup = mid;
    }
    return ill(inf, check(inf));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ill ans;
    while(cin >> n, n) {
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
        ans = binSearch();
        cout << (ans.second == 0 ? s[ans.first] : "Impossibilidade de empate.") << "\n";
    }
    return 0;
}
