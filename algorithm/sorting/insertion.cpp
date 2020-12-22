/// INSERTION SORT ALGORITHM

#include <iostream>

using namespace std;

void insertionSort(int arr[], int n)
{
    int temp, hole;
    for(int i = 1; i < n-1; i++) {
        temp = arr[i];
        hole = i;
        while(hole > 0 && arr[hole-1] > temp) {
            arr[hole] = arr[hole-1];
            hole = hole-1;
        }
        arr[hole] = temp;
    }
}

void printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main()
{
    cout << "### INSERTION SORT ###\n\n";

    int arr[] = {100, 21, 23, -8, 43, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: "; printArr(arr, n);

    insertionSort(arr, n);

    cout << "\n\nAfter sorting: "; printArr(arr, n);
    cout << "\n";

    return 0;
}
