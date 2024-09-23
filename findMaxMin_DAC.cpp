#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to combine the results from two halves
pair<int, int> combineResults(const pair<int, int>& leftResult, const pair<int, int>& rightResult) {
    int overallMin = min(leftResult.first, rightResult.first);
    int overallMax = max(leftResult.second, rightResult.second);
    return {overallMin, overallMax};
}

// Function to find the minimum and maximum values in a subarray using divide and conquer
pair<int, int> divideAndConquer(const vector<int>& arr, int left, int right) {
    // If the array contains only one element
    if (left == right) {
        return {arr[left], arr[right]};
    }

    // If the array contains only two elements
    if (right == left + 1) {
        if (arr[left] < arr[right]) {
            return {arr[left], arr[right]};
        } else {
            return {arr[right], arr[left]};
        }
    }

    // Divide the array into two halves
    int mid = (left + right) / 2;

    // Recursively find the maximum and minimum of the left half
    pair<int, int> leftResult = divideAndConquer(arr, left, mid);

    // Recursively find the maximum and minimum of the right half
    pair<int, int> rightResult = divideAndConquer(arr, mid + 1, right);

    // Combine the results
    return combineResults(leftResult, rightResult);
}

// Main function to initiate the divide and conquer approach
/*pair<int, int> findMaxMin(const vector<int>& arr) {
    return divideAndConquer(arr, 0, arr.size() - 1);
}*/

int main() {
    vector<int> arr = {-3, -5, -1, -2, -4, -8};

    pair<int, int> result = divideAndConquer(arr, 0, arr.size() - 1);
    //pair<int, int> result = findMaxMin(arr);

    cout << "Minimum value: " << result.first << endl;
    cout << "Maximum value: " << result.second << endl;

    return 0;
}
