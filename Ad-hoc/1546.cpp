#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testes;
    int dias;
    int cod;
    cin >> testes;
    for (int i = 0; i < testes; i++) {
        cin >> dias;
        for (int j = 0; j < dias; j++) {
            cin >> cod;
            if (cod == 1) cout << "Rolien\n";
            else if (cod == 2) cout << "Naej\n";
            else if (cod == 3) cout << "Elehcim\n";
            else if (cod == 4) cout << "Odranoel\n";
        }
    }
}