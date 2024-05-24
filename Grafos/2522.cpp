#include <bits/stdc++.h>
using namespace std;


constexpr double INF = 1e7;
int n;
vector<pair<double, double> > p(512);
int marked[512];
double dist[512];

double calcDist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

double solve() {
    fill(marked, marked + n, 0);
    fill(dist, dist + n, INF);
    double aux, mst = 0, min = INF;
    int index, index2;
    index = 0;
    for(int i = 1; i < n; i++) {
        min = INF;
        marked[index] = 1;
        for(int j = 1; j < n; j++) {
            if(marked[j] == 0) {
                aux = calcDist(p[index].first, p[index].second, p[j].first, p[j].second);
                if(aux < dist[j]) dist[j] = aux;
                if(dist[j] < min) { min = dist[j]; index2 = j; }
            }
        }
        mst += min;
        index = index2;
    }
    return mst;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c;
    double x, y;
    cout << fixed;
    cout.precision(2);
    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> p[i].first >> p[i].second;
            p[i].first--; p[i].second--;
        }
        cout << solve() << "\n";
    }
    return 0;
}
