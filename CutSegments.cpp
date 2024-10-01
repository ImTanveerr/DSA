#include <iostream>
#include <vector>
using namespace std;

int CutSegments(int n, int x, int y, int z)
{
    if (n == 0)
    {
        return 0; 
    }
    if (n < 0)
    {
        return -1; 
    }

    int ans1 = CutSegments(n - x, x, y, z);
    int ans2 = CutSegments(n - y, x, y, z);
    int ans3 = CutSegments(n - z, x, y, z);

    int result = max(ans1, max(ans2, ans3));

    if (result == -1) {
        return -1; 
    }

    return result + 1; 
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, x, y, z;
        cin >> n >> x >> y >> z;
        int result = CutSegments(n, x, y, z);
        if (result == -1)
        {
            cout << "Output 0" << endl; 
        }
        else
        {
            cout << "Output "<<result << endl; 
        }
    }
    return 0;
}
