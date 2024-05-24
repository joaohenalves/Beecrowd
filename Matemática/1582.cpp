#include <bits/stdc++.h>
using namespace std;


int mdc(int num1, int num2) {
    if(num1 % num2 == 0) {
        return num2;
    } else {
        return mdc(num2, num1 % num2);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    vector<int> triple (3);
    while(cin >> triple[0] >> triple[1] >> triple[2]) {
        sort(triple.begin(), triple.end());
        cout << "tripla";
        if(pow(triple[2], 2) == pow(triple[0], 2) + pow(triple[1], 2)) {
            cout << " pitagorica";
            if(mdc(triple[2], mdc(triple[1], triple[0])) == 1) {
                cout << " primitiva";
            }
        }
        cout << "\n";
    }
    return 0;
}
