#include <iostream>
#include <vector>
using namespace std;

int findMinCost(vector<int> &cost, int n, vector<int> &temp)
{
    if (n <= 1)
    {
        return 0;
    }

    if (temp[n] != -1)
    {
        return temp[n];
    }

    temp[n] = min(findMinCost(cost, n - 1, temp) + cost[n - 1], findMinCost(cost, n - 2, temp) + cost[n - 2]);

    return temp[n];
}

int MinCostClimbStairs(vector<int> &cost, int n)
{
    vector<int> temp(n + 1, -1);
    return findMinCost(cost, n, temp);
}
int main()
{
    int n;
    cin >> n;
    vector<int> cost;

    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        cost.push_back(v);
    }

    int minCost = MinCostClimbStairs(cost, n);
    cout << "Minimum Cost: " << minCost << endl;


    return 0;
}
