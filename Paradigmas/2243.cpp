#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int heights[51234];
    int n, temp, mx = 0;
    cin >> n;
    heights[0] = heights[n + 1] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> temp;
        heights[i] = min(heights[i - 1] + 1, temp);
    }
    for(int i = n; i > 0; i--) {
        heights[i] = min(heights[i + 1] + 1, heights[i]);
        if(heights[i] > mx) mx = heights[i]; 
    }
    cout << mx << "\n";
    return 0;
}

