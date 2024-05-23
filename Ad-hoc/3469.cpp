#include <bits/stdc++.h>
using namespace std;

#define MAX 1123456

int vet[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> vet[i];
    }
    sort(vet, vet + n);
    if((n & 1) == 0) ans = (vet[n / 2] + vet[n / 2 - 1]) >> 1;
    else ans = vet[n / 2];
    cout << ans << "\n"; 
    return 0;
}
