#include <iostream>
using namespace std;

/* 
    Alisson de Sousa Vieira
    Leonardo de Fontes
*/


void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  
    int n2 = right - mid;    
    
   
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

  
    for (int i = 0; i < n1; i++) {
        *(leftArr + i) = *(arr + left + i);
    }
    for (int j = 0; j < n2; j++) {
        *(rightArr + j) = *(arr + mid + 1 + j);
    }

    int i = 0;   
    int j = 0;  
    int k = left;

    while (i < n1 && j < n2) {
        if (*(leftArr + i) <= *(rightArr + j)) {
            *(arr + k) = *(leftArr + i);
            i++;
        } else {
            *(arr + k) = *(rightArr + j);
            j++;
        }
        k++;
    }

    while (i < n1) {
        *(arr + k) = *(leftArr + i);
        i++;
        k++;
    }

    while (j < n2) {
        *(arr + k) = *(rightArr + j);
        j++;
        k++;
    }
}

void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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

    mergeSort(v, 0, 7);
    cout << "\nAfter sort: ";
    for (int i = 0; i < 8; i++)
    {
        cout << v[i] << " ";
    }
    

    return 0;
}