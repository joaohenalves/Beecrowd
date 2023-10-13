#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int m;

    cin >> n >> m;

    queue<int> inscrs_30d;
    int soma_inscrs_30d = 0;
    int j;
    for (int i = 0; i < 30; i++) {
        cin >>  j;

        inscrs_30d.push(j);
        soma_inscrs_30d += j;
    }

    int num_dias = 0;
    while (n < m) {
        int media_inscrs_30d = ((soma_inscrs_30d / 30)
            + (((soma_inscrs_30d % 30) == 0) ? 0 : 1));

        soma_inscrs_30d -= inscrs_30d.front();
        inscrs_30d.pop();

        soma_inscrs_30d += media_inscrs_30d;
        inscrs_30d.push(media_inscrs_30d);

        num_dias++;
        n += media_inscrs_30d;
    }

    cout << num_dias << "\n";

    return 0;
}