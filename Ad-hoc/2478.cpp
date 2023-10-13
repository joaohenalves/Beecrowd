#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string name, p1, p2, p3;
    map<string, tuple<string, string, string>> names;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> name >> p1 >> p2 >> p3;
        names[name] = make_tuple(p1, p2, p3);
    }
    while(cin >> name >> p1) {
        bool flag = false;
        if(p1 == get<0>(names[name]) || p1 == get<1>(names[name]) || p1 == get<2>(names[name])) flag = true;
        cout << (flag ? "Uhul! Seu amigo secreto vai adorar o/\n" : "Tente Novamente!\n");
    }
}