#include <bits/stdc++.h>
using namespace std;

int selectionSort(vector<int> array, int size) {

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
    int n, size;
    char letter;
    vector<int> letters;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> size;
        for(int j = 0; j < size; j++) {
            cin >> letter;
            letters.push_back((int) letter);
        }
        cout << (selectionSort(letters, size) <= 1 ? "There are the chance.\n" : "There aren't the chance.\n");
        letters.clear();
    }
    return 0;
}