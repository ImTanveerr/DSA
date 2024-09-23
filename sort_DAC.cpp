#include <iostream>
#include <vector>
using namespace std;

// Function to merge two subarrays
void merge( vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    
    int n2 = right - mid;
    

    // Create temporary arrays
     vector<int> L(n1), R(n2);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void divide( vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        divide(arr, left, mid);
        divide(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print an array
void printArray(const  vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {3,6,8,2,5,1,4};
    cout << "Given array is \n";
    printArray(arr);

    divide(arr, 0, arr.size() - 1);

    cout << "\nSorted array is \n";
    printArray(arr);
    return 0;
}
