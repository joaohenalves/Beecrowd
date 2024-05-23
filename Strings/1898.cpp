#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    char c;
    vector<string> n(3);
    int cpf = 0, idx = 1;
    double val;
    while(c = getchar(), c != EOF) {
        if(c == '\n') idx++;
        if(isdigit(c) && cpf < 11) {
            n[0].push_back(c);
            cpf++;
        } else if(isdigit(c) || c == '.') {
            n[idx].push_back(c);
        }
    }
    cout << "cpf " << n[0] << "\n";
    val = floor(stod(n[1]) * 100) / 100 + floor(stod(n[2]) * 100) / 100;
    cout << fixed;
    cout.precision(2);
    cout << val << "\n";
    return 0;
}
