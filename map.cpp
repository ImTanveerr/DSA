#include <iostream>
#include <map>
#include <string>

using namespace std;

void display(map<string, int> &marksMap)
{
    for (auto itr = marksMap.begin(); itr != marksMap.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }
}

int main()
{
    map<string, int> myMap;
    int n;

    while (true)
    {
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Erase" << endl;
        cout << "4. Clear" << endl;
        cout << "5. Emplace_hint" << endl;
        cout << "10. Exit" << endl;

        cout << "Enter any number: ";
        cin >> n;

        switch (n)
        {
        case 1:
        {
            string name;
            int num;
            cout << "Enter name and number: ";
            cin >> name >> num;
            myMap.insert(pair<string, int>(name, num));
            break;
        }
        case 2:
            display(myMap);
            break;
        case 3:
        {
            string name;
            cout << "Enter name to erase: ";
            cin >> name;
            myMap.erase(name);
            break;
        }
        case 4:
            myMap.clear();
            break;
        case 5:
        {
            string name;
            int value;
            cout << "Enter a name and the marks: ";
            cin >> name >> value;
            myMap.emplace_hint(myMap.end(), name, value);
        }
        break;
        case 10:
            return 0;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
