#include <bits/stdc++.h>
using namespace std;

int main(void) {
    
    ios::sync_with_stdio(0);
    cin.tie(0);


    string name;
    unordered_map<string, array<int, 2>> murderers;
    
    for(;;) {
        cin >> name;
        if (cin.eof()) break;
        murderers[name][0]++;
        cin >> name;
        murderers[name][1] = 1;
    }

    vector<pair<string, int>> vet;
    for(auto data : murderers) {
        if(data.second[1] == 0) {
            vet.push_back(make_pair(data.first, data.second[0]));
        }
    }

    sort(vet.begin(), vet.end());
    

    cout << "HALL OF MURDERERS\n";
    
    for(int i = 0; i < vet.size(); i++) {
        cout << vet[i].first << " " << vet[i].second << "\n";
    }

    return 0;

}