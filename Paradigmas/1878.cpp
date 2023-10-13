#include <bits/stdc++.h>
using namespace std;

void search(vector<long long> &results, vector<int> &places, vector<int> &cf, int n, int m) {
    if(places.size() == n) {
        long long tmp = 0;
        for(int j = 0; j < n; j++) {
            tmp += cf[j] * places[j];
        }
        results.push_back(tmp);
        places.pop_back();
        return;
    } else {
        for(int i = 1; i <= m; i++) {
            places.push_back(i);
            search(results, places, cf, n, m);
        }
        places.pop_back();
        return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<long long> results;
    vector<int> places;
    vector<int> cf;
    int n;
    int m;
    int read;

    while(cin >> n){
        bool flag = false;
        cin >> m;
        for(int i = 0; i < n; i++) {
            cin >> read;
            cf.push_back(read);
        }
        search(results, places, cf, n, m);
        sort(results.begin(), results.end());
        auto it = adjacent_find(results.begin(), results.end());
        if(it == results.end()) flag = true;

        if(flag) {
            cout << "Lucky Denis!\n";
        } else {
            cout << "Try again later, Denis...\n";
        }
        cf.clear();
        results.clear();
        places.clear();
    }
    return 0;
}