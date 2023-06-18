#include <iostream>
using namespace std;

/* 
    Alisson de Sousa Vieira
    Leonardo de Fontes
*/

void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) min = j;
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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

    selectionSort(v, 8);
    cout << "\nAfter sort: ";
    for (int i = 0; i < 8; i++)
    {
        cout << v[i] << " ";
    }
    

    return 0;
}

