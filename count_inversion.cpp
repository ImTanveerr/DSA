#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int count = 0;

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
            count += (n1 - i);
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

    return count;
}

int numberOfInversions(vector<int> &arr, int left, int right)
{
    int count = 0;
    if (left < right)
    {

        int mid = left + (right - left) / 2;

        count += numberOfInversions(arr, left, mid);
        count += numberOfInversions(arr, mid + 1, right);

        count += merge(arr, left, mid, right);
    }
    return count;
}

/*int numberOfInversions(vector<int> &arr, int n)
{

    return divide(arr, 0, n - 1);
}*/

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    int inversions = numberOfInversions(arr, 0,arr.size()-1);
    cout << "Number of inversions: " << inversions << endl;
    return 0;
}
