#include <iostream>
using namespace std;

void swap(int *x, int *y) {
  int tmp  = *x;
  *x = *y;
  *y = tmp;
}

void selection_sort(int arr[], int size) {
  int i, j, min_id;
  for(i = 0; i < size - 1; i++) {
    min_id = i;
    for(j = i + 1; j < size; j++) {
        if(arr[j] < arr[min_id])
          min_id = j;
    }
    swap(&arr[i], &arr[min_id]);
  }
}

/* inplace sorting algorithm, dont required extra space
 1. Minimum time complexity: O(n)
 2. Maximum time complexity: O(n)2
 3. Stable sort: YES
 4. sorting inplace */
void insertion_sort(int arr[], int size) {
  for(int i = 0; i < size - 1; i++) {
    int j = i+1;
    while(j > 0 && (arr[j] < arr[j-1])) {
      swap(&arr[j], &arr[j-1]);
      j--;
    }
  }
}

int partition(int arr[], int start, int end) {
  int i = start;
  int pivot = arr[end];
  int c;
  for(c=start; c < end; c++) {
    if(arr[c] < pivot) {
      swap(&arr[c], &arr[i]);
      i++;
    }
  }
  swap(&arr[c], &arr[i]); // put the pivot element in its proper place
  return c; // return the position of the pivot
}

void quick_sort(int arr[], int start, int end) {
  if(start < end) {
    int pivotIndex = partition(arr, start, end);
    quick_sort(arr, start, pivotIndex - 1); // sort the left side of pivot
    quick_sort(arr, pivotIndex + 1, end);   // sort the right side of pivot
  }
}


void displayArr(int arr[], int size) {
  int i;
  for( i = 0; i < size; i++)
    cout << " " << arr[i];
  cout << endl;
}

int main() {
  int arrNumber[] = {6, 2, 5, 9, 3, 1};
  int arrSize = sizeof(arrNumber)/sizeof(arrNumber[0]);

  //selection_sort(arrNumber, arrSize);
  //insertion_sort(arrNumber, arrSize);
  quick_sort(arrNumber, 0, arrSize - 1);

  displayArr(arrNumber, arrSize);
  return 0;
}
