#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<string, string> list;
    string name, answer, sorteado;
    int tam = 0;
    cin >> name;

    while (name != "FIM")
    {
        cin >> answer;
        list[name] = answer;
        if (answer == "YES")
        {
            if ((int)name.length() > tam)
            {
                sorteado = name;
                tam = name.length();
            }
        }
        cin >> name;
    }
    for (auto item : list)
    {
        if (item.second == "YES")
        {
            cout << item.first << "\n";
        }
    }
    for (auto item : list)
    {
        if (item.second == "NO")
        {
            cout << item.first << "\n";
        }
    }
    cout << "\n"
         << "Amigo do Habay:\n"
         << sorteado << "\n";
}