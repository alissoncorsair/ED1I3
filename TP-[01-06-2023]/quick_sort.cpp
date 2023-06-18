#include <iostream>
using namespace std;

/* 
    Alisson de Sousa Vieira
    Leonardo de Fontes
*/

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char **argv)
{
    int v[8] = {49, 38, 58, 87, 34, 93, 26, 13};
    cout << "Before sort: ";
    for (int i = 0; i < 8; i++)
    {
        cout << v[i] << " ";
    }
    quickSort(v, 0, 7);
    cout << "\nAfter sort: ";
    for (int i = 0; i < 8; i++)
    {
        cout << v[i] << " ";
    }
    

    return 0;
}