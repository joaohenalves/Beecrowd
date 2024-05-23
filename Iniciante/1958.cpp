#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string nums;
    long double numld;
    cin >> nums;
    if(nums[0] != '-') cout << "+";
    numld = stold(nums);
    cout.precision(4);
    cout << scientific;
    cout << uppercase << numld << "\n";
}
