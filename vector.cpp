#include <iostream>
#include <vector>
using namespace std;

void reverse(const vector<int> &vec)
{
    vector<int>::const_reverse_iterator rit;
    for (rit = vec.rbegin(); rit != vec.rend(); ++rit)
    {
        cout << *rit << " ";
    }
    cout << endl;
}

void display(const vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec1;
    vector<int> vec2(5, 15);
    int n;
    vector<int>::iterator it;

    while (true)
    {
        cout << "1. Insert at beginning" << endl;
        cout << "2. Insert at a position" << endl;
        cout << "3. Erase at the beginning" << endl;
        cout << "4. Erase at a Position" << endl;
        cout << "5. Erase from one index to another" << endl;
        cout << "6. Erase till the position" << endl;
        cout << "7. Swap the vectors" << endl;
        cout << "8. Clear the vector" << endl;
        cout << "9. Emplace at the beginning" << endl;
        cout << "10. Emplace at a position" << endl;
        cout << "11. Emplace at the end" << endl;
        cout << "12. Emplace Back" << endl;
        cout << "13. Push at the end" << endl;
        cout << "14. Pop from the end" << endl;
        cout << "15. Display" << endl;
        cout << "16. Reverse" << endl;

        cout << "Enter any number: "<<endl;
        cin >> n;

        switch (n)
        {
        case 0:
            return 0;
        case 1:
        {
            int element;
            cout << "Enter an Element: ";
            cin >> element;
            it = vec1.begin();
            vec1.insert(it, element);
            break;
        }
        case 2:
        {
            int element, position;
            cout << "Enter a Position: ";
            cin >> position;
            cout << "Enter an Element: ";
            cin >> element;
            if (position >= 0 && position <= vec1.size())
            {
                vec1.insert(vec1.begin() + position, element);
            }
            else
            {
                cout << "Invalid position!" << endl;
            }
            break;
        }
        case 3:
            if (!vec1.empty())
            {
                vec1.erase(vec1.begin());
            }
            break;
        case 4:
        {
            int position;
            cout << "Enter a Position: ";
            cin >> position;
            if (position >= 0 && position < vec1.size())
            {
                vec1.erase(vec1.begin() + position);
            }
            else
            {
                cout << "Invalid position!" << endl;
            }
            break;
        }
        case 5:
        {
            int start, end;
            cout << "Enter start and end positions: ";
            cin >> start >> end;
            if (start >= 0 && end <= vec1.size() && start < end)
            {
                vec1.erase(vec1.begin() + start, vec1.begin() + end);
            }
            else
            {
                cout << "Invalid positions!" << endl;
            }
            break;
        }
        case 6:
        {
            int position;
            cout << "Enter a Position: ";
            cin >> position;
            if (position >= 0 && position <= vec1.size())
            {
                vec1.erase(vec1.begin(), vec1.begin() + position);
            }
            else
            {
                cout << "Invalid positions!" << endl;
            }
            break;
        }
        case 7:
            vec1.swap(vec2);
            break;
        case 8:
            vec1.clear();
            break;
        case 9:
        {
            int element;
            cout << "Enter an Element: ";
            cin >> element;
            vec1.emplace(vec1.begin(), element);
            break;
        }
        case 10:
        {
            int element, position;
            cout << "Enter a Position: ";
            cin >> position;
            cout << "Enter an Element: ";
            cin >> element;
            if (position >= 0 && position <= vec1.size())
            {
                vec1.emplace(vec1.begin() + position, element);
            }
            else
            {
                cout << "Invalid position!" << endl;
            }
            break;
        }
        case 11:
        {
            int element;
            cout << "Enter an Element: ";
            cin >> element;
            vec1.emplace(vec1.end(), element);
            break;
        }
        case 12:
        {
            int element;
            cout << "Enter an Element: ";
            cin >> element;
            vec1.emplace_back(element);
            break;
        }
        case 13:
        {
            int element;
            cout << "Enter an Element: ";
            cin >> element;
            vec1.push_back(element);
            break;
        }
        case 14:
            if (!vec1.empty())
            {
                vec1.pop_back();
            }
            break;
        case 15:
            display(vec1);
            break;
        case 16:
            reverse(vec1);
            break;
        default:
            cout << "Invalid command!" << endl;
            break;
        }
    }

    return 0;
}
