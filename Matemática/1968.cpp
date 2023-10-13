#include <bits/stdc++.h>
using namespace std;

vector<int> numList (10000001, 1);

void sieveOfEratosthenes(int n) {
    int aux, m;
    for(int i = 2; i <= n; i++) {
        if(numList[i] == 1) {
            for(int j = i; j <= n; j += i) {
                for(aux = j, m = 0; aux % i == 0; aux /= i, m++);
                numList[j] *= (m + 1);
            }
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int a, b, n, limit;
    long long aux;
    long long counter = 0;
    cin >> a >> b >> n;
    sieveOfEratosthenes(b);
    for(int i = a; i <= b; i++) {
        if(numList[i] == n) counter++;
    }
    limit = (b - a + 1) - counter;
    aux = counter;
    for(int j = 1; j < limit; j++) {
        counter *= aux;
        counter %= 1000000007;
    }
    cout << counter << "\n";
    return 0;
}