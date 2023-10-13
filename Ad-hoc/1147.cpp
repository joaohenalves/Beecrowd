#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y, kx, ky, counter;
    string pos;
    int cases = 1;

    for(;;) {
        int board[8][8] = {0};
        counter = 0;
        cin >> pos;
        if(pos == "0") break;
        kx = ((int) pos[0]) - 49;
        ky = ((int) pos[1]) - 97;
        for(int i = 0; i < 8; i++) {
            cin >> pos;
            x = ((int) pos[0]) - 49;
            y = ((int) pos[1]) - 97;
            if(x - 1 >= 0) {
                if(y - 1 >= 0) {
                    board[x-1][y-1] = 1;
                }
                if(y + 1 < 8) {
                    board[x-1][y+1] = 1;
                }
            }
        }

        if(kx - 2 >= 0) {
            if(ky - 1 >= 0 && board[kx-2][ky-1] == 0) counter++;
            if(ky + 1 < 8 && board[kx-2][ky+1] == 0) counter++;
        }
        if(kx + 2 < 8) {
            if(ky - 1 >= 0 && board[kx+2][ky-1] == 0) counter++;
            if(ky + 1 < 8 && board[kx+2][ky+1] == 0) counter++;
        }
        if(ky - 2 >= 0) {
            if(kx - 1 >= 0 && board[kx-1][ky-2] == 0) counter++;
            if(kx + 1 < 8 && board[kx+1][ky-2] == 0) counter++;
        }
        if(ky + 2 < 8) {
            if(kx - 1 >= 0 && board[kx-1][ky+2] == 0) counter++;
            if(kx + 1 < 8 && board[kx+1][ky+2] == 0) counter++;
        }

        cout << "Caso de Teste #" << cases << ": " << counter << " movimento(s).\n";
        cases++;

    }


    return 0;
}