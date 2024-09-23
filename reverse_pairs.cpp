#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int CountPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > 2 * arr[right])
            right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int divide(vector<int> &arr, int left, int right)
{
    int count = 0;
    if (left < right)
    {

        int mid = left + (right - left) / 2;

        count += divide(arr, left, mid);
        count += divide(arr, mid + 1, right);

        count += CountPairs(arr, left, mid, right);
        merge(arr, left, mid, right);
    }
    return count;
}

int main()
{
    vector<int> arr = {4, 1, 2, 3, 1};
    int reversepairs = divide(arr, 0, arr.size() - 1);
    cout << "Number of Reverse Pairs: " << reversepairs << endl;

    return 0;
}
