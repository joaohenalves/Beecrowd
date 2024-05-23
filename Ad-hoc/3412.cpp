#include <bits/stdc++.h>
using namespace std;
 
#define MAX 112345

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    double g;
    string s, name;
    cin >> n;
    vector<vector<double>> grades(70);
    cin.ignore();
    for(int i = 0; i < n; i++) {
        getline(cin, name);
        getline(cin, s);
        istringstream iss(s);
        while(iss >> g) {
            grades[i].push_back(g);
        }
        cout << fixed;
        cout.precision(1);
        cout << name << ": ";
        if(grades[i].size() == 1) {
            cout << grades[i][0] / 2 << "\n";
        } else if(grades[i].size() == 2) {
            cout << (grades[i][0] + grades[i][1]) / 2 << "\n";
        } else if(grades[i].size() == 3) {
            cout << (grades[i][0] + grades[i][1] + grades[i][2]) / 3 << "\n";
        } else {
            sort(grades[i].begin(), grades[i].end());
            cout << (grades[i][3] + grades[i][2] + grades[i][1]) / 3 << "\n";
        }
    }    
    return 0;
}

