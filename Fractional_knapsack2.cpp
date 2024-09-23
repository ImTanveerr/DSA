/*Knapsack with Variable Item Fractions:

You are allowed to take fractional weights of the items, but each item has a minimum fraction that must be taken
(at least 30% of each item’s weight must be taken).
The knapsack has a capacity of 80, and the items are as follows:
Item 1: Weight = 20, Value = 50
Item 2: Weight = 50, Value = 100
Item 3: Weight = 30, Value = 60
How would you approach this problem to maximize the total value? */

#include <iostream>
using namespace std;
#include <vector>

void maximizeValue(vector<pair<int, int>> &items, int n, int capacity)
{
    double fraction[n];
    for (int i = 0; i < n; i++)
    {
        fraction[i] = (double)items[i].second / items[i].first;
    }
    for (int k = 0; k < n; k++)
    {
        for (int j = 1; j < n; j++)
        {
            if (fraction[k] < fraction[j])
            {
                swap(fraction[k], fraction[j]);
                swap(items[k], items[j]);
                k = j;
            }
        }
    }

    int weight[n];
    double maxvalue = 0;
    for (int i = 0; i < n; i++)
    {
        weight[i] = items[i].first * 30 / 100;
    }

    for (int i = 0; i < n; i++)
    {
        maxvalue += (double)weight[i] * fraction[i];
        capacity -= weight[i];
        items[i].first -= weight[i];
    }
    cout << "Max Value: " << maxvalue << "   " << capacity << endl;

    for (int i = 0; i < n; i++)
    {
        if (items[i].first <= capacity)
        {
            maxvalue += (double)fraction[i] * items[i].first;
            capacity -= items[i].first;
        }
        else
        {
            maxvalue += (double)fraction[i] * capacity;
            capacity = 0;
        }

        cout << "Max Value: " << maxvalue << "   " << capacity << endl;
    }

    cout << "Max Value: " << maxvalue << endl;
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
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> weight >> value;
        items.push_back({weight, value});
    }

    maximizeValue(items, n, capacity);

    return 0;
}
