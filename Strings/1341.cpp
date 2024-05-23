#include <bits/stdc++.h>
 
using namespace std;

int lcs(const string &s1, const string &s2) {
    int size1 = s1.size();
    int size2 = s2.size();
    int memo[size1 + 1][size2 + 1];
    memset(memo, 0, sizeof(memo));

    for (int i = 1; i <= size1; i++) {
        for (int j = 1; j <= size2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1] + 1;
            } else {
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }
    return memo[size1][size2];
}

string buildSteps(int x, int y, string steps, vector<string> matrix) {
    string temp = "";
    x--;
    y--;
    temp.push_back(matrix[x][y]);
    for(int i = 0; i < steps.size(); i++) {
        if(steps[i] == 'N') x--;
        else if(steps[i] == 'E') y++;
        else if(steps[i] == 'W') y--;
        else if(steps[i] == 'S') x++;
        temp.push_back(matrix[x][y]);
    }
    return temp;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, rowSize, colSize, moves, x, y, result;
    int counter = 1;
    string temp, childOne, childTwo, steps;
    vector<string> matrix;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> rowSize >> colSize;
        for(int j = 0; j < rowSize; j++) {
            cin >> temp;
            matrix.emplace_back(temp);
        }
        cin >> moves >> x >> y;
        getline(cin, steps);
        getline(cin, steps);
        childOne = buildSteps(x, y, steps, matrix);
        cin >> moves >> x >> y;
        getline(cin, steps);
        getline(cin, steps);
        childTwo = buildSteps(x, y, steps, matrix);
        result = lcs(childOne, childTwo);
        cout << "Case " << counter << ": " << childOne.size() - result << " " << childTwo.size() - result << "\n";
        counter++;
        matrix.clear();
    }
    return 0;
}
