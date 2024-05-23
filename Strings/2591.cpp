#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string k;
    int a, b, n;
    cin >> n;
    while(n--) {
        a = b = 0;
        cin >> k;
        for(int i = 1; i < k.size(); i++) {
            if(k[i] == 'a') a++;
            else break;
        }
        for(int i = 4 + a; i < k.size(); i++) {
            if(k[i] == 'a') b++;
            else break;
        }
        cout << 'k';
        for(int i = 0; i < a * b; i++) {
            cout << 'a';
        }
        cout << "\n";
    }
    return 0;
}
