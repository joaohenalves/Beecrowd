#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, sz, flag;
    while(cin >> n) {
        list<int> books;
        sz = 0;
        for(int i = 0; i < n; i++) {
            cin >> m;
            flag = false;
            for(auto it = books.begin(); it != books.end(); it++) {
                if((*it) == m) {
                    books.erase(it);
                    flag = true;
                    break;
                }
            }
            if(books.size() == 4) books.pop_back();
            if(!flag) sz++;
            books.push_front(m);
        }
        cout << sz << "\n";
    }
    return 0;
}
