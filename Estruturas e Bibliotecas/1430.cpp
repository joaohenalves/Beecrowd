#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    map<char, double> notes;
    string music;
    double temp = 0;
    int counter = 0;
    notes['W'] = 1;
    notes['H'] = 1.0/2;
    notes['Q'] = 1.0/4;
    notes['E'] = 1.0/8;
    notes['S'] = 1.0/16;
    notes['T'] = 1.0/32;
    notes['X'] = 1.0/64;
    for(;;) {
        getline(cin, music);
        if(music.size() == 1) break;
        for(int i = 1; i < music.size(); i++) {
            if(music[i] != '/') {
                temp += notes[music[i]];
            } else {
                if(temp == 1) counter++;
                temp = 0;
            }
        }
        cout << counter << "\n";
        counter = 0;
    }
    return 0;
}