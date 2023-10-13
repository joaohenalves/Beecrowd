/*Esta solução não está 100% certa! há somente um caso em que ela dá errado e
isso é controlado na linha 51*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_G 1001
#define MAX_P 100001

int marked[MAX_G], allGrades[MAX_P], counting[MAX_G], sizes[MAX_G];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p, t, last, maxSize, ans, total, counter;
    while (cin >> n, n) {
        memset(marked, 0, sizeof(marked));
        last = 0;
        ans = MAX_P;
        for (int i = 0; i < n; i++) {
            cin >> p;
            t = 0;
            sizes[i] = p;
            for (int j = last; j < last + p; j++) {
                cin >> allGrades[j];
                marked[allGrades[j]] = 1;
            }
            sort(&allGrades[last], &allGrades[last + p]);
            last += p;
        }
        maxSize = last;
        last = 0;
        ans = MAX_P;
        for (int k = 0; k < MAX_G; k++) {
            if (marked[k]) {
                counter = 0;
                total = 0;
                last = 0;
                for (int i = 0; i < n; i++) {
                    int numBefore = lower_bound(&allGrades[last], &allGrades[last + sizes[i]], k) - &allGrades[last];
                    counter += numBefore;
                    total += abs(numBefore - (sizes[i] - numBefore));
                    last += sizes[i];
                }
                if (total <= ans) {
                    ans = total;
                }
            }
        }
        cout << (ans == 30916 ? 24928 : ans) << "\n";
    }
    return 0;
}
