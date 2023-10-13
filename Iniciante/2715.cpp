#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, temp;
    long long totalSum;
    long long half;
    while(cin >> n) {
        totalSum = 0;
        vector<long long> tasks (n);
        for(long long i = 0; i < n; i++) {
            cin >> temp;
            totalSum += temp;
            tasks[i] = totalSum;
        }
        half = totalSum/2;
        auto it = lower_bound(tasks.begin(), tasks.end(), half);
        auto prev = it;
        advance(prev, -1);
        if(llabs(*it - (totalSum - *it)) <= llabs(*prev - (totalSum - *prev))) {
            cout << llabs(*it - (totalSum - *it)) << "\n";
        } else {
            cout << llabs(*prev - (totalSum - *prev)) << "\n";
        }
    }
    return 0;
}