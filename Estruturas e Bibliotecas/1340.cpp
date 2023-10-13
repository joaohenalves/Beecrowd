#include <bits/stdc++.h>
using namespace std;

bitset<3> testStructure;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, op, num;
    while(cin >> n) {
        stack<int> st;
        queue<int> q;
        priority_queue<int> pq;
        for(int i = 0; i < n; i++) {
            cin >> op >> num;
            if(op == 1) {
                st.push(num);
                q.push(num);
                pq.push(num);
            } else {
                if(st.top() != num) {
                    testStructure.set(0);
                }
                if(q.front() != num) {
                    testStructure.set(1);
                }
                if(pq.top() != num) {
                    testStructure.set(2);
                }
                st.pop();
                q.pop();
                pq.pop();
            }
        }
        if(testStructure.all()) cout << "impossible\n";
        else if(testStructure.count() <= 1) cout << "not sure\n";
        else {
            if(!testStructure[0]) cout << "stack\n";
            else if(!testStructure[1]) cout << "queue\n";
            else if(!testStructure[2]) cout << "priority queue\n";
        }
        testStructure.reset();
    }
    return 0;
}