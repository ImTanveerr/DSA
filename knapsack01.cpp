#include <iostream>
#include <vector>
using namespace std;
int kanpsack01(vector<pair<int, int>> &items, int n, int capacity)
{
    int include = 0;
    int exclude = 0;
    if (n==0 || capacity==0)
    {
        return 0;
    }
    

    if (items[n-1].first <= capacity)
    {
        include = items[n-1].second + kanpsack01(items, n - 1, capacity - items[n-1].first);
    }
    else
    {
        exclude = 0 + kanpsack01(items, n - 1, capacity);
    }


    return  max(exclude, include);;
}

int main()
{
    vector<pair<int, int>> items;
    int n, capacity;
    cout << "Enter the capacity of knapsack: " << endl;
    cin >> capacity;
    cout << "Enter how many items you have: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value, weight;
        cout << "Enter weight and value of item " << i + 1 << ": ";
        cin >> weight >> value;
        items.push_back({weight, value});
    }

    /*cout << "weight, value " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "(" << items[i].first << ", " << items[i].second << ")" << endl;
    }*/

    int maxknapsack = kanpsack01(items, n, capacity);
    cout << "MAX: " << maxknapsack << endl;

    return 0;
}
