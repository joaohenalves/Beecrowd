#include <bits/stdc++.h>
using namespace std;

char keys[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, rest, step = 0;
    string result;
    cin >> n;
    while(n) {
        rest = n % 10;
        if(rest <= 3 && rest != 0) while(rest--) result += keys[step];
        else if(rest == 4) {result += keys[step + 1]; result+= keys[step];}
        else if(rest >= 5 && rest < 9) {
            while(rest - 5 > 0) {result += keys[step]; rest--;}
            result += keys[step + 1];
        } else if (rest == 9) { result += keys[step + 2]; result += keys[step];}
        n /= 10;
        step += 2;
    }
    reverse(result.begin(), result.end());
    cout << result << "\n";
    return 0;
}
