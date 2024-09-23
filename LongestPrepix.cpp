#include <iostream>
#include <vector>
#include <string>
using namespace std;

void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

int partition(vector<string> &str, int low, int high)
{
    string pivot = str[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (str[j] <= pivot)
        {
            i++;
            swap(str[i], str[j]);
        }
    }
    swap(str[i + 1], str[high]);
    return (i + 1);
}

void quickSort(vector<string> &str, int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, str[pi] is now at right place
        int pi = partition(str, low, high);

        // Recursively sort elements before partition and after partition
        quickSort(str, low, pi - 1);
        quickSort(str, pi + 1, high);
    }
}

void SortString(vector<string> &str)
{
    quickSort(str, 0, str.size() - 1);
}

string LongestCommonPrefix(const vector<string> &str)
{
    string first = str[0];
    string last = str[str.size() - 1];
    int i = 0;
    for (i = 0; i < first.size(); ++i)
    {
        if (first[i] != last[i])
        {
            break;
        }
    }

    return first.substr(0, i);
}

int main()
{
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    SortString(str);
    string result = LongestCommonPrefix(str);
    cout << result << endl;

    return 0;
}
