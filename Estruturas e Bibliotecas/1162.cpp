#include <bits/stdc++.h>
using namespace std;

int counter;

void bubbleSort(int array[], int size) {
    bool flag;
    int temp; 
    for (int i = size - 1; i > 0; i--) {
        flag = false;
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = true;
                counter++;
            }
        }
        if (flag == false) {break;}
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t, temp;
    cin >> n;
    int trains[50];
    for(int i = 0; i < n; i++) {
        cin >> t;
        for(int j = 0; j < t; j++) {
            cin >> trains[j];
        }
        counter = 0;
        bubbleSort(trains, t);
        cout << "Optimal train swapping takes " << counter << " swaps.\n";
    }
    return 0;
}