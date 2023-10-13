#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, counter;
    char c;
    bool flag;
    string temp, temp2;
    while(cin >> n) {
        stack<char> lt;
        counter = 0;
        while(n--) {
            flag = true;
            temp = "";
            temp2 = "";
            if(lt.empty()) {
                lt.push('F');
                lt.push('A');
                lt.push('C');
                lt.push('E');
            }
            for(int i = 0; i < 4; i++) {
                cin >> c;
                temp2 += c;
                if(c == lt.top()) {
                    temp += lt.top();
                    lt.pop();
                } else {
                    flag = false;
                }
            }
            if(flag) counter++;
            else {
                for(int j = temp.size() - 1; j >= 0; j--) {
                    lt.push(temp[j]);
                }
                for(int k = 0; k < 4; k++) {
                    lt.push(temp2[k]);
                }
            }
        }
        cout << counter << "\n";
    }
    return 0;
}