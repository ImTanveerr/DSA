#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int CoinChange(vector<int> &coins, int n, int value)
{
    int result = INT_MAX;
    if (value == 0)
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= value)
        {
            int ans = 1 + CoinChange(coins, n, value - coins[i]);
            if (ans < result)
            {
                result = ans;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> coins;
    int n, value;
    cout << "Enter how many coins you have: " << endl;
    cin >> n;
    cout << "Enter the target value " << endl;
    cin >> value;

    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        coins.push_back(v);
    }
    int minCoins = CoinChange(coins, n, value);
    cout<<"Minimum number of coins needed: "<<minCoins<<endl;
}
