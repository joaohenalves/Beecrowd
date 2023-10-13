#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, m, v, t, total, done, timeControl, highestTime, mostValuable, index;
    while (cin >> n >> m)
    {
        vector<priority_queue<int>> tasks(m + 1);
        done = 0;
        highestTime = 0;
        total = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v >> t;
            total += v;
            tasks[t].emplace(v);
            if (t > highestTime)
            {
                highestTime = t;
            }
        }
        timeControl = highestTime;
        while (timeControl > 0)
        {
            mostValuable = 0;
            index = 0;
            for (int j = timeControl; j <= highestTime; j++)
            {
                if (!tasks[j].empty() && tasks[j].top() > mostValuable)
                {
                    mostValuable = tasks[j].top();
                    index = j;
                }
            }
            tasks[index].pop();
            done += mostValuable;
            timeControl--;
        }
        cout << total - done << "\n";
        tasks.clear();
    }
    return 0;
}