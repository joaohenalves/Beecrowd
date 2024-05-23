#include <bits/stdc++.h>
using namespace std;

#define MAX 21234
#define MAXS 1000000000
typedef pair<int, int> ii;

int guesses[MAX], misses[MAX];
unordered_multiset<int> aux;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ii ans;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> guesses[i];
    }
    for(int i = 0 ; i < n; i++) {
        cin >> misses[i];
    }
    sort(misses, misses + n);
    sort(guesses, guesses + n);
    ans.first = 0;
    if(guesses[0] - misses[0] >= 1) {
        ans.first = guesses[0] - misses[0];
        for(int i = 1; i < n; i++) {
            if(guesses[i] - misses[i] != ans.first) {
                ans.first = 0;
                break;
            }
        }
    }
    ans.second = 0;
    if(guesses[n - 1] + misses[0] <= MAXS) {
        ans.second = guesses[n - 1] + misses[0];
        for(int i = n - 2; i >= 0; i--) {
            if(guesses[i] + misses[n - i - 1] != ans.second) {
                ans.second = 0;
                break;
            }
        }
    }
    if(ans.first == 0 && ans.second == 0) {
        for(int i = 0; i < n - 1; i++) aux.insert(misses[i]);
        ans.first = guesses[0] + misses[n - 1];
        for(int i = 1; i < n; i++) {
            auto it = aux.find(abs(ans.first - guesses[i]));
            if(it == aux.end()) {
                ans.first = 0;
                break;
            } else aux.erase(it);
        }
        aux.clear();
        for(int i = 0; i < n - 1; i++) aux.insert(misses[i]);
        ans.second = guesses[n - 1] - misses[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            auto it = aux.find(abs(ans.second - guesses[i]));
            if(it == aux.end()) {
                ans.second = 0;
                break;
            } else aux.erase(it);
        }
    }
    if(ans.first != 0 && ans.first != ans.second) cout << ans.first << "\n";
    if(ans.second != 0) cout << ans.second << "\n";
    return 0;
}
