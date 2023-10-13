#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int s, counter;
    long long temp;
    vector<long long> nlog;
    vector<long long> quad;
    cin >> s;
    nlog.reserve(s);
    quad.reserve(s);
    for(int i = 0; i < s; i++) {
        cin >> temp;
        quad.emplace_back(temp);
    }
    sort(quad.begin(), quad.end());
    for(int j = 0; j < s; j++) {
        cin >> temp;
        nlog.emplace_back(temp);
    }
    sort(nlog.begin(), nlog.end());
    int iq = s - 1;
    int in = s - 1;
    counter = 0;
    while(iq >= 0 && in >= 0) {
        if(quad[iq] < nlog[in]) {
            counter++;
            in--;
            iq--;
        } else {
            iq--;
        }
    }
    cout << counter << "\n";
    return 0;
}