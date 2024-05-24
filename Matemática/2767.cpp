#include<bits/stdc++.h>
using namespace std;

#define MAX 112345

long long hn[MAX], mn[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k, x;
	long long total;
	while(cin >> n >> m >> k) {
		memset(hn, 0, sizeof(hn));
		memset(mn, 0, sizeof(mn));
		for(int i = 0; i < n; i++) {
			cin >> x;
			x %= k;
			hn[x]++;
		}
		for(int i = 0; i < m; i++) {
			cin >> x;
			x %= k;
			mn[x]++;
		}
		total = 0;
		for(int i = 0; i < k; i++) {
			total += hn[i] * mn[(k - i) % k];
		}
		cout << total << "\n";
	}
	return 0;
}
