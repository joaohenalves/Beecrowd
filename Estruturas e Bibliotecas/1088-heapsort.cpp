#include <bits/stdc++.h>
using namespace std;

int counter;

void createHeap(vector<int> &array, int i, int size) {

    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && array[left] > array[i]) {
        max = left;
    }
    if (right < size && array[right] > array[max]) {
        max = right;
    }

    if (max != i) {
        int aux = array[i];
        array[i] = array[max];
        array[max] = aux;
        counter++;
        createHeap(array, max, size);
    }
}


void heapSort(vector<int> &array, int size) {

    for (int k = size/2-1; k >= 0; k--) {
        createHeap(array, k, size);
    }

    for (int k = size-1; k > 0; k--) {
        int aux = array[0];
        array[0] = array[k];
        array[k] = aux;
        counter++;
        createHeap(array, 0, k);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, temp;
    cin >> n;
    while(n != 0) {
        vector<int> numbers;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            numbers.push_back(temp);
        }
        counter = 0;
        heapSort(numbers, n);
        if(counter % 2 == 0) {
            cout << "Carlos\n";
        } else {
            cout << "Marcelo\n";
        }
        cin >> n;
    }

    return 0;
}