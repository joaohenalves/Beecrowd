#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ull a, b;
    int diff;
    while(cin >> a >> b){
        if(a == 0 && b == 0) break;
        a ^= b;
        diff = 0;
        while(a){
            if(a & 1) diff++;
            a >>= 1;
        }
        cout << diff << "\n";
    }
  return 0;
}
