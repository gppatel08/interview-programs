#include <iostream>
using namespace std;

int linearSearch(int arrNumber[], int size, int searchValue) {
  for(int i = 0; i < size; i++) {
    if(searchValue == arrNumber[i]) {
      return i;
    }
  }
  return -1;
}

/* Pre-condition: Array must be in sorted order
   Cuts search space in half after each comparison */
int binarySearch(int arrNumber[], int size, int searchValue) {
  int low = 0;
  int high = size - 1;
  int mid;

  while(low <= high) {
    mid = (low + high)/2;

    if(arrNumber[mid] == searchValue)
      return mid;
    else if(arrNumber[mid] < searchValue)
      low = mid + 1;
    else
      high = mid - 1;
  }
}

int main() {
  int arr[] = {15, 23, 7, 45, 87, 16};
  int valueSearch;

  cout << "Enter an integer: ";
  cin >> valueSearch;

  //int result = linearSearch(arr, sizeof(arr)/sizeof(arr[0]), valueSearch);
  int result = binarySearch(arr, sizeof(arr)/sizeof(arr[0]), valueSearch);

  if(result >= 0)
    cout << "Number found: " << arr[result] << endl;
  else
    cout << "Number not found: " << endl;
     
  return 0;
}
