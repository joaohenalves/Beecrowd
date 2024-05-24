#include <bits/stdc++.h>
using namespace std;

#define MAX 2000000

int numList[2123456], counter[2123456];

void sieve() {
    int aux, m;
    for(int i = 2; i <= MAX; i++) {
        if(numList[i] == 1) {
            for(int j = i; j <= MAX; j += i) {
                for(aux = j, m = 0; aux % i == 0; aux /= i, m++);
                numList[j] *= (m + 1);
            }
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    for(int i = 1; i <= MAX; i++) numList[i] = 1;
    sieve();
    counter[0] = numList[0] = numList[1] = 0;
    for(int i = 2; i <= MAX; i++) {
        if(numList[numList[i]] == 2) {
            counter[i] = counter[i - 1] + 1;
        } else counter[i] = counter[i - 1];
    }
    while(cin >> n) {
        cout << counter[n] << "\n";
    }
    return 0;
}
