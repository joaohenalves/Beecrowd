#include <bits/stdc++.h>

using namespace std;

int selectionSort(int array[], int size) {
    int swap;
    int indexMin;
    int counter = 0;
    for (int i = 0; i < size - 1; i++) {
        indexMin = i;
        for (int j = i + 1; j < size; j++) {
            if (array[indexMin] > array[j]) {
                indexMin = j;
            }
        }
        if(indexMin != i) {
            swap = array[indexMin];
            array[indexMin] = array[i];
            array[i] = swap;
            counter++;
        }
    }
    return counter;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l, n, aux2;
    while (cin >> l) {
        int total = 0;
        int loop = 0;
        cin >> n;
        int containers[l][n];
        bool flag = false;
        int aux[l];
        for (int i = 0; i < l; i++) {
            int div = 0;
            int countp = 0;
            int countl = 0;
            int counte = 0;
            for (int j = 0; j < n; j++) {
                loop++;
                cin >> aux2;
                containers[i][j] = aux2;
                if(j == 0) {
                aux[i] = aux2;
                div = aux2 / n;
                } else {
                    aux2 /= n;
                    if(aux2 == div-1) {countl++;}
                    else if(aux2 == div+1){countp++;}
                    else if(aux2 == div){counte++;}
                }          
            }
            if(!(countl == n-1 || (countp == 1 && counte == n-2))) {
                flag = true;
                break;
            }
        }
        while(loop < l * n) {
            cin >> aux2;
            loop++;
        }
        for(int x = 1; x < l && !flag; x++) {
            for(int y = 0; y < n && !flag; y++) {
                if(containers[x][y] % n != containers[0][y] % n) {
                    flag = true;
                }
            }
        }
        if (flag) {
            cout << "*\n";
        } else {
            total = selectionSort(containers[0], n) + selectionSort(aux, l);
            cout << total << "\n";
        }        
    }
}