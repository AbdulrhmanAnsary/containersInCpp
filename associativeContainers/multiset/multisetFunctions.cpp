#include <iostream>
#include <set>

using namespace std;

template <typename T, typename order>
void printSet(const multiset<T, order> &container)
{
    cout << "{";
    for (auto item = container.begin(); item != container.end(); item++)
    {
        cout << *item;
        if (next(item) != container.end())
            cout << ", ";
    }
    cout << "}\n";
}

void reversePrinting(const multiset<int> &container)
{
    cout << "{";
    for (auto item = container.rbegin(); item != container.rend(); item++)
    {
        cout << *item;
        if (next(item) != container.rend())
            cout << ", ";
    }
    cout << "}\n";
}

int main()
{
    multiset<int> nums = {4, 3, 2, 1, 4, 1, 5, 2};
    multiset<int> oddNums = {1, 3, 5, 7, 9, 11};
    multiset<int, greater<int>> descendingNums = {10, 40, 20, 40, 50, 30, 10, 50};

    cout << "nums:\n";
    printSet(nums);
    cout << "The reverse printing for nums:\n";
    reversePrinting(nums);
    cout << "descendingNums:\n";
    printSet(descendingNums);

    cout << "\nIs nums empty: " << nums.empty() << endl;
    cout << "nums size: " << nums.size() << endl;
    cout << "The max size of elements count: " << nums.max_size() << endl;

    cout << "\nAdd new element to nums using insert:\n";
    nums.insert(nums.begin(), 8);
    printSet(nums);

    cout << "\nAdd new element to nums using emplace:\n";
    nums.emplace(6);
    printSet(nums);

    cout << "\nHow often does item '4' exist in nums: " << nums.count(4) << endl;
    cout << "How often does item '9' exist in nums: " << nums.count(9) << endl;

    auto it = nums.find(5);
    if (it != nums.end())
        cout << "Find the number '5' in nums: " << *it << endl;
    else
        cout << "The number '5' was not found in nums.\n";

    it = nums.find(22);
    if (it != nums.end())
        cout << "Find the number '22' in nums: " << *it << endl;
    else
        cout << "The number '22' was not found in nums.\n";

    cout << "\nRemove the first element in nums:\n";
    nums.erase(nums.begin());
    printSet(nums);

    cout << "\nRemove from 3 to 5 in nums:\n";
    set<int>::iterator six = nums.find(6);
    nums.erase(nums.find(3), six);
    printSet(nums);

    cout << "\nSwapping nums with oddNums:\n";
    nums.swap(oddNums);
    cout << "nums: ";
    printSet(nums);
    cout << "oddNums: ";
    printSet(oddNums);

    return 0;
}