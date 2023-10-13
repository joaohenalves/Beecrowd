#include <bits/stdc++.h>
using namespace std;


int ans;

void merge(int array[], int start, int middle, int finalIndex) {
    int auxArray[finalIndex - start + 1];
    int i = start;
    int j = middle + 1;
    int k = 0;
    while (i <= middle && j <= finalIndex) {
        if (array[i] <= array[j]) {
            auxArray[k] = array[i];
            i++;
        } else {
            auxArray[k] = array[j];
            ans += middle - i + 1; // Count the number of swaps
            j++;
        }
        k++;
    }
    while (i <= middle) {
        auxArray[k] = array[i];
        k++;
        i++;
    }
    while (j <= finalIndex) {
        auxArray[k] = array[j];
        k++;
        j++;
    }
    for (k = start; k <= finalIndex; k++) {
        array[k] = auxArray[k - start];
    }
}

void mergeSort(int array[], int start, int finalIndex) {
    if (start < finalIndex) {
        int middle = (start + finalIndex) / 2;
        mergeSort(array, start, middle);
        mergeSort(array, middle + 1, finalIndex);
        merge(array, start, middle, finalIndex);
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int numbers[112345];
    while(n != 0) {
        for(int i = 0; i < n; i++) {
            cin >> numbers[i];
        }
        ans = 0;
        mergeSort(numbers, 0, n - 1);
        if(ans % 2 == 0) {
            cout << "Carlos\n";
        } else {
            cout << "Marcelo\n";
        }
        cin >> n;
    }

    return 0;
}