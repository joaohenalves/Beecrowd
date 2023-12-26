#include <bits/stdc++.h>
using namespace std;

int piles[1123];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int boxes, numPiles, n, box, target, height, ansRight, ansLeft;
    while(cin >> boxes >> numPiles, boxes) {
        ansRight = ansLeft = 0;
        for(int i = 0; i < numPiles; i++) {
            cin >> n;
            piles[i] = n;
            for(int j = 0; j < n; j++) {
                cin >> box;
                if(box == 1) {
                    target = i;
                    height = j + 1;
                }
            }
        }
        for(int i = target + 1; i < numPiles; i++) {
            if(piles[i] >= height) ansRight += piles[i] - (height - 1);
            else break;
        }
        for(int i = target - 1; i >= 0; i--) {
            if(piles[i] >= height) ansLeft += piles[i] - (height - 1);
            else break;
        }
        cout << min(ansLeft, ansRight) + piles[target] - height << "\n";
    }
    return 0;
}
