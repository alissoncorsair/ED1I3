#include <iostream>
using namespace std;

/* 
    Alisson de Sousa Vieira
    Leonardo de Fontes
*/

void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


int main(int argc, char **argv)
{
    int v[8] = {49, 38, 58, 87, 34, 93, 26, 13};
    cout << "Before sort: ";
    for (int i = 0; i < 8; i++) {
        cout << v[i] << " ";
    }
    insertionSort(v, 8);
    cout << "\nAfter sort: ";
    for (int i = 0; i < 8; i++) {
        cout << v[i] << " ";
    }
    
    return 0;
}