#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
typedef long long ll;

int n, bit[MAX], orig[MAX];

void setbit(int i, int delta) {
    while(i <= n) {
        bit[i] += delta;
        i += i & -i;
    }
}

ll getbit(int i) {
    ll ans = 0;
    while(i) {
        ans += bit[i];
        i -= i & -i;
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int temp;
    char op;
    cin >> n;
    memset(bit, 0, sizeof(bit));
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        setbit(i, temp);
        orig[i] = temp;
    }
    while(cin >> op >> temp) {
        if(op == 'a') {
            setbit(temp, -orig[temp]);
        } else {
            cout << getbit(temp - 1) << "\n";
        }
    }
    return 0;
}
