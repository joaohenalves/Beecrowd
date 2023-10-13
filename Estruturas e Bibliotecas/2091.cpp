#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long int a;
    cin >> n;
    while (n != 0)
    {
        unordered_map<long long, int> ms;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            ms[a]++;
        }
        for (auto item : ms)
        {
            if (item.second % 2 == 1)
            {
                cout << item.first << "\n";
                break;
            }
        }
        cin >> n;
    }
}