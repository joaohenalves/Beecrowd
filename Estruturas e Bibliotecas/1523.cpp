#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<int> parkedCars;
    int n, cap, arrival, departure;
    cin >> n >> cap;
    while(n > 0) {
        bool evaluation = true;
        for(int i = 0; i < n; i++) {
            cin >> arrival >> departure;
            if(evaluation == false) continue;
            if(!parkedCars.empty()) {
                while(!parkedCars.empty()) {
                    if(parkedCars.top() <= arrival) {
                        parkedCars.pop();
                    } else break;
                }
                if(parkedCars.empty()) {
                    parkedCars.push(departure);
                    continue;
                }
                if(parkedCars.top() > departure && parkedCars.size() < cap) {
                    parkedCars.push(departure);
                } else {
                    evaluation = false;
                }
            } else parkedCars.push(departure);
        }
        cout << (evaluation ? "Sim\n" : "Nao\n");
        while(!parkedCars.empty()) {
            parkedCars.pop();
        }
        cin >> n >> cap;
    }

    return 0;
}