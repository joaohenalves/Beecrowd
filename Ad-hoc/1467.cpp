#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    while(cin >> a >> b >> c) {
        if((a == 0 && (b & c)) || (a == 1 && !(b | c))) cout << 'A';
        else if((b == 0 && (a & c)) || (b == 1 && !(a | c))) cout << 'B';
        else if((c == 0 && (b & a)) || (c == 1 && !(b | a))) cout << 'C';
        else cout << '*';
        cout << "\n";
    }
    return 0;
}
