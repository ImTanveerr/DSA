#include <iostream>
#include <list>
#include <iterator>
#include <utility>
#include <cmath>
#include <string>
#include <cctype>

using namespace std;

void display(list<int> &lst)
{
    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void reverse(list<int> &lst)
{
    lst.reverse();
    display(lst);
}

struct is_near {
    bool operator()(double first, double second) {
        return std::fabs(first - second) < 0.5;
    }
};

bool same_integral_part(double first, double second) {
    return static_cast<int>(first) == static_cast<int>(second);
}
bool single_digit (const int& value) { return (value<10); }

struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

int main()
{
    list<int> list1;
    int n;
    list<int>::iterator it;

    while (true)
    {
        cout << "1. Push front" << endl;
        cout << "2. Assign" << endl;
        cout << "3. Pop front" << endl;
        cout << "4. Splice" << endl;
        cout << "5. Remove" << endl;
        cout << "6. Sort" << endl;
        cout << "7. Remove duplicates or unique" << endl;
        cout << "8. Clear the list" << endl;
        cout << "9. Emplace at the beginning" << endl;
        cout << "10. Emplace at a position" << endl;
        cout << "11. Emplace at the end" << endl;
        cout << "12. Emplace back" << endl;
        cout << "13. Push at the end" << endl;
        cout << "14. Pop from the end" << endl;
        cout << "15. Display" << endl;
        cout << "16. Reverse" << endl;
        cout << "17. Emplace front" << endl;
        cout << "18. Erase at the beginning" << endl;
        cout << "19. Erase at a position" << endl;

        cout << "Enter any number: " << endl;
        cin >> n;

        switch (n)
        {
        case 0:
            return 0;
        case 1:
        {
            int element;
            cout << "Enter an element: ";
            cin >> element;
            list1.push_front(element);
            break;
        }
        case 2:
        {
            int value, figure;
            cout << "Enter a figure: ";
            cin >> figure;
            cout << "Enter the value: ";
            cin >> value;
            list1.assign(figure, value);

            // second.assign(first.begin(), first.end());
            // int myints[] = {17,76,7,4,6};
            // list1.assign(myints, myints + 3);
            break;
        }
        case 3:
            if (!list1.empty())
            {
                list1.pop_front();
            }
            break;

        case 4:
        {
            list<int> list2;
            int value;
            cout << "Enter values for the second list (end with -1): ";
            while (true) {
                cin >> value;
                if (value == -1) break;
                list2.push_back(value);
            }
            cout << "Enter a position to splice: ";
            int pos;
            cin >> pos;
            auto it = list1.begin();
            advance(it, pos);
            list1.splice(it, list2);
            break;
        }
        case 5:
        {
            int value;
            cout << "Enter a value: ";
            cin >> value;
            if (!list1.empty())
            {
                list1.remove(value);
                // list1.remove_if(single_digit);
                // list1.remove_if(is_odd());
            }
            break;
        }
        case 6:
        {
            list1.sort();
            // list1.sort(compare_nocase); // for string
            break;
        }
        case 7:
        {
            list1.unique();
            list1.unique(same_integral_part);
            list1.unique(is_near());
            break;
        }
        case 8:
        {
            list1.clear();
            break;
        }
        case 9:
        {
            int element;
            cout << "Enter an element: ";
            cin >> element;
            list1.emplace(list1.begin(), element);
            break;
        }
        case 10:
        {
            int element, position;
            cout << "Enter a position: ";
            cin >> position;
            cout << "Enter an element: ";
            cin >> element;
            auto it = list1.begin();
            advance(it, position);
            list1.emplace(it, element);
            break;
        }
        case 11:
        {
            int element;
            cout << "Enter an element: ";
            cin >> element;
            list1.emplace(list1.end(), element);
            break;
        }
        case 12:
        {
            int element;
            cout << "Enter an element: ";
            cin >> element;
            list1.emplace_back(element);
            break;
        }
        case 13:
        {
            int element;
            cout << "Enter an element: ";
            cin >> element;
            list1.push_back(element);
            break;
        }
        case 14:
        {
            if (!list1.empty())
            {
                list1.pop_back();
            }
            break;
        }
        case 15:
        {
            display(list1);
            break;
        }
        case 16:
        {
            reverse(list1);
            break;
        }
        case 17:
        {
            list<pair<int, char>> list2;
            int num;
            char ch;
            cout << "Enter a number and a character: ";
            cin >> num >> ch;
            list2.emplace_front(num, ch);

            for (auto &x : list2)
            {
                cout << "(" << x.first << ", " << x.second << ") ";
            }
            cout << endl;

            break;
        }
        case 18:
        {
            if (!list1.empty())
            {
                list1.erase(list1.begin());
            }
            break;
        }
        case 19:
        {
            int position;
            cout << "Enter a position: ";
            cin >> position;
            if (position >= 0 && position < list1.size())
            {
                auto it = list1.begin();
                advance(it, position);
                list1.erase(it);
            }
            else
            {
                cout << "Invalid position!" << endl;
            }
            break;
        }
        default:
            cout << "Invalid command!" << endl;
            break;
        }
    }

    return 0;
}
