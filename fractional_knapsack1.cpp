/*
Knapsack with Multiple Items and High Capacity:

You have a knapsack with a capacity of 1000 units and the following items:
Item 1: Weight = 300, Value = 500
Item 2: Weight = 200, Value = 300
Item 3: Weight = 400, Value = 700
Item 4: Weight = 350, Value = 450
Item 5: Weight = 150, Value = 200
How would you maximize the value? Solve for both time and space efficiency.*/

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

    double maxvalue = 0;
    for (int i = 0; i < n; i++)
    {
        if (items[i].first <= capacity)
        {
            maxvalue += (double)items[i].second;
            capacity -= items[i].first;
        }
        else 
        {
            maxvalue += ((double) capacity / items[i].first) * items[i].second;
            capacity -= items[i].first;
            break;
        }
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

    /* cout << "weight, value " << endl;
     for (int i = 0; i < n; i++)
     {
         cout  <<"(" << items[i].first << ", " << items[i].second << ")" << endl;
     }*/

    maximizeValue(items, n, capacity);

    return 0;
}