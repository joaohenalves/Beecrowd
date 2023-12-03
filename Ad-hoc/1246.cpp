#include <bits/stdc++.h> 
using namespace std; 

typedef pair<int, int> ii;
 
 
int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, q, id, s, ans;
    int s2, id2, u;
    char op;
    while(cin >> c >> q) {
        list<ii> spots;
        spots.emplace_back(c, 0);
        ans = 0;
        while(q--) {
            cin >> op >> id;
            if(op == 'C') {
                cin >> s;
                for(auto it = spots.begin(); it != spots.end(); it++) {
                    if((*it).second == 0 && (*it).first >= s) {
                        spots.insert(it, make_pair(s, id));
                        ans += 10;
                        (*it).first -= s;
                        if((*it).first == 0) spots.erase(it);
                        break;
                    }
                }
            } else if(op == 'S') {
                for(auto it = spots.begin(); it != spots.end(); it++) {
                    if((*it).second == id) {
                        if(it != spots.begin()) {
                            auto it2 = it;
                            advance(it2, -1);
                            if((*it2).second == 0) {
                                (*it).first += (*it2).first;
                                spots.erase(it2);
                            }
                        }
                        auto it3 = it;
                        advance(it3, 1);
                        if(it3 != spots.end() && (*it3).second == 0) {
                            (*it3).first += (*it).first;
                            spots.erase(it);
                        } else (*it).second = 0;
                        break;
                    }
                }
            }
        }
        cout << ans << "\n";
    } 
    return 0; 
}
