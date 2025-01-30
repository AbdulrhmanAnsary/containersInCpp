#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template <typename T1, typename T2>
void printPair(const pair<T1, T2> &container)
{
    cout << container.first << " : " << container.second << endl;
}

template <typename T1, typename T2>
void printVectorPair(const vector<pair<T1, T2>> &container)
{
    for (const auto &item : container)
        cout << item.first << " : " << item.second << endl;
}

int main()
{
    // Pairs initialization methods
    pair<string, int> p1("p1", 1);
    pair<string, int> p2 = make_pair("p2", 2);
    pair<string, int> p3 = {"p3", 3};

    pair<string, pair<int, float>> bookInfo;                          // Nested pairs
    vector<pair<int, string>> employeeInfo;                           // Vector of pairs
    vector<pair<int, string>> studentsInfo{{1, "abdo"}, {2, "saad"}}; // Initialized vector of pairs with items
    vector<pair<string, string>> status = {{"fatma", "married"}, {"sara", "single"}};

    printPair(p1);
    printPair(p2);
    printPair(p3);

    cout << "========================\n";

    // Adding values using push_back
    employeeInfo.push_back(make_pair(1234, "Ahmid"));
    employeeInfo.push_back(pair<int, string>(1235, "Mahmod"));
    employeeInfo.push_back({1236, "Kalid"});
    employeeInfo.push_back({1237, "maher"});

    printVectorPair(employeeInfo);
    cout << "========================\n";

    vector<pair<int, string>>::iterator item; // You can used auto insted of writing the whole type
    for (item = employeeInfo.begin(); item != employeeInfo.end(); item++)
        cout << item->first << " : " << item->second << endl;

    cout << "========================\n";
    printVectorPair(studentsInfo);

    cout << "========================\n";
    printVectorPair(status);

    cout << "\nEnter the book title: ";
    getline(cin, bookInfo.first);

    cout << "Enter the book id: ";
    if (!(cin >> bookInfo.second.first))
    {
        cerr << "Invalid input for book ID.\n";
        return 1;
    }

    cout << "Enter the book price: ";
    if (!(cin >> bookInfo.second.second))
    {
        cerr << "Invalid input for book price.\n";
        return 1;
    }

    cout << "\n";
    cout << bookInfo.first << " : " << bookInfo.second.first << " : " << bookInfo.second.second << endl;

    // Overwriting the values in bookInfo
    bookInfo.first = "Flow";
    bookInfo.second.first = 3;
    bookInfo.second.second = 2.5;

    cout << bookInfo.first << " : " << bookInfo.second.first << " : " << bookInfo.second.second << endl;

    return 0;
}