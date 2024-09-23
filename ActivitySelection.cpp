#include <iostream>
#include <vector>
using namespace std;

void SortbyFinish(vector<pair<int, int>> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].second > arr[j + 1].second)
            {
                swap(arr[j], arr[j + 1]);
            }
            else if (arr[j].second == arr[j + 1].second)
            {
                if (arr[j].first > arr[j + 1].first)
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
}

void printMaxActivities(vector<pair<int, int>> &arr)
{
    SortbyFinish(arr);

    int prev = 0, count = 1;
    cout << "The following activities are selected: \n";
    cout << "(" << arr[prev].first << ", " << arr[prev].second << ") ";

    for (int next = 1; next < arr.size(); next++)
    {
        if (arr[next].first >= arr[prev].second)
        {
            cout << "(" << arr[next].first << ", " << arr[next].second << ") ";

            prev = next;
            count++;
        }
    }
    cout << endl;
    cout << "Total number of selected activities: " << count << endl;
}

int main()
{
    vector<pair<int, int>> train = {{8, 12}, {6, 9}, {11, 14}, {2, 7}, {1, 7}, {12, 20}, {7, 12}, {13, 19}};
    printMaxActivities(train);

    for (const auto &t : train)
    {
        cout << "Start: " << t.first << ", Finish: " << t.second << endl;
    }
}