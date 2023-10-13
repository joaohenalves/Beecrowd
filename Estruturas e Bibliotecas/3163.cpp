#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string temp;
    int index = 0, counter = 0, countPrinted = 0;
    vector<queue<string> > dir(4);
    for(;;) {
        getline(cin, temp);
        if(temp[0] == '0') break;
        if(temp[0] == '-') {
            index = (stoi(temp) * -1) - 1;
            index = 2 * (index % 2) + index / 2;
        } else {
            dir[index].push(temp);
            counter++;
        }
    }
    while(countPrinted < counter) {
        for(int i = 0; i < 4; i++) {
            if(!dir[i].empty()) {
                cout << dir[i].front();
                dir[i].pop();
                countPrinted++;
                if(countPrinted < counter) cout << " ";
            }
        }
    }
    cout << "\n";
    return 0;
}