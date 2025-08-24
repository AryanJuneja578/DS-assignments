#include <iostream>
#include <algorithm>
using namespace std;
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; 

        if (arr[mid] == target) {
            return mid; 
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1; 
        }
    }
    return -1; 
}

int main() {
    int arr[] = {2, 4, 7, 10, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort (arr,arr+n);

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int result = binarySearch(arr, n, target);

    if (result != -1)
        cout << "Element found at position number " << result +1 << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
