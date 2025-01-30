#include <iostream>
#include <map>
#include <iterator> // for std::next and std::prev

using namespace std;

template <typename key, typename T, typename order = less<key>>
void printMap(const multimap<key, T, order> &container)
{
    cout << "{";
    for (auto item = container.begin(); item != container.end(); item++)
    {
        cout << item->first << " : " << item->second;
        if (next(item) != container.end())
            cout << ", ";
    }
    cout << "}\n";
}

template <typename key, typename T>
void reversePrinting(const multimap<key, T> &container)
{
    cout << "{";
    for (auto item = container.rbegin(); item != container.rend(); item++)
    {
        cout << item->first << " : " << item->second;
        if (next(item) != container.rend())
            cout << ", ";
    }
    cout << "}\n";
}

int main()
{
    multimap<int, string> nums = {{4, "four"}, {3, "three"}, {1, "first one"}, {2, "two"}, {1, "one"}, {5, "five"}};
    multimap<int, string> oddNums = {{1, "one"}, {3, "three"}, {5, "five"}, {7, "seven"}, {9, "nine"}, {11, "eleven"}};
    multimap<int, string, greater<int>> descendingNums = {{10, "ten"}, {40, "forty"}, {20, "twenty"}, {50, "fifty"}, {30, "thirty"}};

    cout << "nums:\n";
    printMap(nums);
    cout << "The reverse printing for nums:\n";
    reversePrinting(nums);
    cout << "descendingNums:\n";
    printMap(descendingNums);

    cout << "\nIs nums empty: " << nums.empty() << endl;
    cout << "nums size: " << nums.size() << endl;

    cout << "\nReach the value of a specific item in nums:\n";
    auto it = nums.find(2);  // Referes to the firest element has the key '2', If the key isn't exist it will return nums.end()
    if (it != nums.end())
        cout << it->second << endl;
    else
        cout << "Key not found\n";

    cout << "Change the value with the key '2':\n";
    if (it != nums.end())
        it->second = "eighty seven";
    printMap(nums);

    cout << "\nAdd '8' to nums using insert:\n";
    nums.insert({8, "eight"}); // A copy of the item that has been added returns, { } is a pair
    printMap(nums);

    cout << "\nAdd '99' to nums using pair:\n";
    nums.insert({99, "ninety nine"});
    printMap(nums);

    cout << "\nAdd '16' to nums using emplace:\n";
    nums.emplace(16, "sixteen"); // A copy of the item that has been added returns
    printMap(nums);

    cout << "\nRemove '3' from nums:\n";
    nums.erase(3);
    printMap(nums);

    cout << "\nRemove the first element from nums:\n";
    nums.erase(nums.begin());
    printMap(nums);

    cout << "\nHow meny elements have the same key '9' in nums: " << nums.count(9) << endl;
    cout << "How  meny elements have the same key '2' in nums: " << nums.count(2) << endl;

    auto it2 = nums.find(5);
    if (it2 != nums.end())
        cout << "Find the number '5' in nums: " << it2->second << endl;
    else
        cout << "The number '5' was not found in nums.\n";

    cout << "\nRemove a range from '4' to '8' in nums:\n";
    auto start = nums.find(4); // The start of range
    auto end = nums.find(8);   // The end of range
    if (start != nums.end() && end != nums.end())
        nums.erase(start, next(end)); // Deletion will be stopped after "end"
    printMap(nums);

    cout << "\nSwapping nums with oddNums:\n";
    nums.swap(oddNums);
    cout << "nums: ";
    printMap(nums);
    cout << "oddNums: ";
    printMap(oddNums);

    return 0;
}