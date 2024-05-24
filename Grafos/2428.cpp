#include <bits/stdc++.h>
using namespace std;

bool check(int PM, int PN, int QM, int QN) {
	return (PM * QN == PN * QM);
}

int A, B, C, D;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> A >> B >> C >> D;
    if (check(A, B, C, D) || check(A, D, B, C) || check(A, C, D, B)) {
			cout << "S\n";
	} else cout << "N\n";
	return 0;
}
