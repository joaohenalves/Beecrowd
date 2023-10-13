#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str1;
    int counter = 0;
    getline(cin, str1);
    for(int i = 0; i < str1.size(); i++) {
        if(str1[i] == '(') counter++;
        else if(str1[i] == ')' && counter > 0) counter--;
    }
    if(counter) cout << "Ainda temos " << counter << " assunto(s) pendente(s)!\n";
    else cout << "Partiu RU!\n";
    return 0;
}