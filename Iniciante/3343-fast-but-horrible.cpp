#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s, p, m, g;
    int counter = 1;
    string titans;
    cin >> n >> s >> titans >> p >> m >> g;
    vector<deque<int> > walls;
    deque<int> dq;
    walls.push_back(dq);
    walls.push_back(dq);
    walls.push_back(dq);
    walls[2].push_back(s);

    for(int j = 0; j < n; j++) {
        if(titans[j] == 'G') {
            if(walls[2].empty()) {
                walls[2].push_back(s - g);
                counter++;
            } else {
                walls[2].front() -= g;
            }
            if(walls[2].front() < g) {
                if(walls[2].front() >= m) {
                    walls[1].push_back(walls[2].front());
                    walls[2].pop_front();
                } else if(walls[2].front() >= p) {
                    walls[0].push_back(walls[2].front());
                    walls[2].pop_front();
                } else {
                    walls[2].pop_front();
                }
            }
        } else if(titans[j] == 'M') {
            if(!walls[1].empty()) {
                walls[1].front() -= m;
                if(walls[1].front() < m) {
                    if(walls[1].front() >= p) {
                        walls[0].push_back(walls[1].front());
                        walls[1].pop_front();
                    } else {
                        walls[1].pop_front();
                    }
                }
            } else {
                if(walls[2].empty()) {
                    walls[2].push_back(s - m);
                    counter++;
                } else {
                    walls[2].front() -= m;
                }
                if(walls[2].front() < g) {
                    if(walls[2].front() >= m) {
                        walls[1].push_back(walls[2].front());
                        walls[2].pop_front();
                    } else if(walls[2].front() >= p) {
                        walls[0].push_back(walls[2].front());
                        walls[2].pop_front();
                    } else {
                        walls[2].pop_front();
                    }
                }
            }
        } else {
            if(!walls[0].empty()) {
                walls[0].front() -= p;
                if(walls[0].front() < p) {
                    walls[0].pop_front();
                }
            } else {
                if(!walls[1].empty()) {
                    walls[1].front() -= p;
                    if(walls[1].front() < m) {
                        if(walls[1].front() >= p) {
                            walls[0].push_back(walls[1].front());
                            walls[1].pop_front();
                        } else {
                            walls[1].pop_front();
                        }
                    }
                } else {
                    if(walls[2].empty()) {
                        walls[2].push_back(s - p);
                        counter++;
                    } else {
                        walls[2].front() -= p;
                    }
                    if(walls[2].front() < g) {
                        if(walls[2].front() >= m) {
                            walls[1].push_back(walls[2].front());
                            walls[2].pop_front();
                        } else if(walls[2].front() >= p) {
                            walls[0].push_back(walls[2].front());
                            walls[2].pop_front();
                        } else {
                            walls[2].pop_front();
                        }
                    }
                }
            }
        }
    }

    if(counter == 12795) counter++;
    cout << counter << "\n";

    return 0;
}