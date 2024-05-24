#include <iostream>
#include <tgmath.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int total;
    int limit;
    int num;
    cin >> n;

    for(int i = 0; i < n; i++) {
        total = 0;
        cin >> num;
        if(n == 0) break;
        limit = (int) sqrt(num);
        for(int i = 1; i <= limit; i++) {
            if(num % i == 0) {
                total += i;
                if(i != num/i) {
                    total += num/i;
                }
            }
        }
        cout << total << "\n";
    }
    return 0;
}
