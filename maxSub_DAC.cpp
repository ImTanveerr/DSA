#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the maximum crossing subarray sum
int maxCrossingSum(const vector<int>& arr, int left, int mid, int right) {
    // Include elements on the left of mid
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    // Include elements on the right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    // Return sum of elements on left and right of mid
    // Also consider the case when the subarray is entirely on the left or right side
    return left_sum + right_sum;
}

// Function to find the maximum subarray sum using divide and conquer
int maxSubArraySum(const vector<int>& arr, int left, int right) {
    // Base case: only one element
    if (left == right)
        return arr[left];

    // Find the middle point
    int mid = left + (right - left) / 2;
    //int mid = (left + right) / 2;

    // Recursively find the maximum subarray sum for the left and right halves
    int left_max = maxSubArraySum(arr, left, mid);
    int right_max = maxSubArraySum(arr, mid + 1, right);
    int cross_max = maxCrossingSum(arr, left, mid, right);

    // Return the maximum of the three
    return max(left_max, max(right_max, cross_max));
}

int main() {
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    int max_sum = maxSubArraySum(arr, 0, arr.size()- 1);
    cout << "Maximum subarray sum is " << max_sum << endl;
    return 0;
}
