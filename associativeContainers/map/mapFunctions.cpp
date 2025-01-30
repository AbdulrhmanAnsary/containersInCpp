#include <iostream>
#include <map>

using namespace std;

template <typename key, typename T, typename order>
void printMap(const map<key, T, order> &container)
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
void reversePrinting(const map<key, T> &container)
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
    map<int, string> nums = {{4, "four"}, {3, "three"}, {2, "two"}, {1, "one"}, {5, "five"}};
    map<int, string> oddNums = {{1, "one"}, {3, "three"}, {5, "five"}, {7, "seven"}, {9, "nine"}, {11, "eleven"}};
    map<int, string, greater<int>> descendingNums = {{10, "ten"}, {40, "forty"}, {20, "twenty"}, {50, "fifty"}, {30, "thirty"}};

    cout << "nums:\n";
    printMap(nums);
    cout << "The reverse printing for nums:\n";
    reversePrinting(nums);
    cout << "descendingNums:\n";
    printMap(descendingNums);

    cout << "\nIs nums empty: " << nums.empty() << endl;
    cout << "nums size: " << nums.size() << endl;
    cout << "The max size of elements count: " << nums.max_size() << endl;

    cout << "\nReach the value of a specific item in nums:\n";
    // Returns out_of_range, if the value of key does not represent the key value of any item in the object.
    cout << nums.at(2) << endl;

    cout << "Change the value with the key '2':\n";
    nums.at(2) = "eighty seven";
    printMap(nums);

    cout << "\nReach the value of a specific item in nums:\n";
    // If the value of a key is passed that does not exist in the place of the parameter key,
    // the item will be added as a new item in the object
    cout << nums[4] << endl;

    cout << "Change the value with the key '2':\n";
    nums.at(4) = "fifty five";
    printMap(nums);

    cout << "\nAdd '8'' to nums using insert:\n";
    nums.insert({8, "eight"}); // A copy of the item that has been added returns, { } is a pair
    printMap(nums);

    cout << "\nAdd '99' to nums using pair:\n";
    nums[99] = "ninety nine";
    printMap(nums);

    cout << "\nAdd '16' to nums using implace:\n";
    nums.emplace(16, "sixteen"); // A copy of the item that has been added returns
    printMap(nums);

    cout << "\nRemove '3' from nums:\n";
    nums.erase(3);
    printMap(nums);

    cout << "\nRemove the first element from nums:\n";
    nums.erase(nums.begin());
    printMap(nums);

    cout << "\nIs the number '9' in nums: " << nums.count(9) << endl;
    cout << "Is the number '2' in nums: " << nums.count(2) << endl;

    auto it = nums.find(5); // Return an object 'iterator' that refers to the item's address in memory, The object will equal end() value if isn't exist.
    if (it != nums.end())
        cout << "Find the number '5' in nums: " << it->second << endl;
    else
        cout << "The number '5' was not found in nums.\n";

    it = nums.find(22);
    if (it != nums.end())
        cout << "Find the number '22' in nums: " << it->second << endl;
    else
        cout << "The number '22' was not found in nums.\n";

    cout << "\nRemove a range from '4' to '8' in nums:\n";
    auto start = nums.find(4);                     // The start of range
    map<int, string>::const_iterator end = nums.find(8); // The end of range
    if (start != nums.end() && end != nums.end())
        nums.erase(start, end); // Deletion will be stopped at "end"
    printMap(nums);

    cout << "\nSwapping nums with oddNums:\n";
    nums.swap(oddNums);
    cout << "nums: ";
    printMap(nums);
    cout << "oddNums: ";
    printMap(oddNums);

    return 0;
}