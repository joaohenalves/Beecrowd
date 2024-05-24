#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

int quad[MAX], nlog[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int s, iq, in, counter;
    cin >> s;
    for(int i = 0; i < s; i++) {
        cin >> quad[i];
    }
    sort(quad, quad + s);
    for(int j = 0; j < s; j++) {
        cin >> nlog[j];
    }
    sort(nlog, nlog + s);
    iq = s - 1;
    in = s - 1;
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
