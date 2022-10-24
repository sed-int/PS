#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int Partition(int arr[], int start, int end){
	int piv = arr[end];
	int i = start - 1;

	for (int j = start; j < end; j++){
		if (arr[j] < piv){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[end]);
	return (i + 1);
}

void QuickSort(int arr[], int start, int end){
	if (start < end) {
	int pIndex = Partition(arr, start, end);
	QuickSort(arr, start, pIndex - 1);
	QuickSort(arr, pIndex + 1, end);
	}
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
  
int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}