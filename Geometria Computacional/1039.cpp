#include<bits/stdc++.h>
using namespace std;

#define MAX 112345

int n, k;

double d(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	double x1, y1, x2, y2, v, r1, r2;
	while(cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2) {
		if(r1 >= d(x1, y1, x2, y2) + r2) cout << "RICO\n";
		else cout << "MORTO\n";
	}
	return 0;
}

