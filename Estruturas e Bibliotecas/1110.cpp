#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, temp;
    cin >> n;
    while (n != 0)
    {
        queue<int> dq;
        vector<int> discarded;
        for (int i = 1; i <= n; i++)
        {
            dq.push(i);
        }
        while (dq.size() >= 2)
        {
            temp = dq.front();
            dq.pop();
            discarded.push_back(temp);
            temp = dq.front();
            dq.pop();
            dq.push(temp);
        }
        cout << "Discarded cards: ";
        for (int j = 0; j < discarded.size() - 1; j++)
        {
            cout << discarded[j] << ", ";
        }
        cout << discarded[discarded.size() - 1] << "\n"
             << "Remaining card: " << dq.front() << "\n";
        cin >> n;
    }
}