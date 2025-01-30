#include <iostream>
#include <forward_list>
#include <vector>
#include "../../data_structure_tools.h"

using namespace std;

int main(int argc, char *argv[])
{
    DataStructureTools tools;
    forward_list<int> nums;
    forward_list<int> evenNums = {2, 4, 6, 8, 10, 12};
    forward_list<int> oddNums = {1, 3, 5, 7};
    forward_list<int> duplicateNums = {5, 2, 7, 2, 4, 5, 3, 8, 9, 1, 2, 7, 7, 8, 9};

    cout << "After resizing oddNum and fill the new space using -1:\n";
    oddNums.resize(7, -1);
    tools.printContainer(oddNums);

    cout << "\nAfter assigning to nums:\n";
    nums.assign({10, 20, 30, 40, 50, 60});
    tools.printContainer(nums);

    cout << "\nAdd new element at the begin using emplace_front:\n";
    nums.emplace_front(5);
    tools.printContainer(nums);

    cout << "\nAdd new element at the begin using push_front:\n";
    nums.push_front(3);
    tools.printContainer(nums);

    // The problem with forward list is that it is a singly linked list,
    // which means that to reach a specific element you must go through all the elements from the beginning.

    cout << "\nAdd new element using emplace_after:\n";
    nums.emplace_after(nums.begin(), 2);
    tools.printContainer(nums);

    cout << "\nAdd new element using insert_after:\n";
    nums.insert_after(nums.begin(), 1);
    tools.printContainer(nums);

    cout << "\nRemove the second element:\n";
    nums.erase_after(nums.begin());
    tools.printContainer(nums);

    cout << "\nAfter swapping nums with evenNums:\n";
    nums.swap(evenNums);
    cout << "nums: ";
    tools.printContainer(nums);
    cout << "evenNums: ";
    tools.printContainer(evenNums);

    cout << "\nAfter using splice_after with nums and oddNums:\n";
    nums.splice_after(nums.begin(), oddNums);
    cout << "nums: ";
    tools.printContainer(nums);
    cout << "oddNums: ";
    tools.printContainer(oddNums);

    cout << "\nRemove -1 from nums:\n";
    nums.remove(-1);
    tools.printContainer(nums);

    cout << "\nUse remove_if to remove items smaller than 3 :\n";
    nums.remove_if([](const int &value) { return value < 3; });
    tools.printContainer(nums);
    
    cout << "\nPrint dupicateNums:\n";
    tools.printContainer(duplicateNums);
    cout << "Delete duplicate values from duplicateNums:\n";
    duplicateNums.sort();
    duplicateNums.unique(); // The duplicate elements must be adjacent to each other so we used sort() befor unique().
    tools.printContainer(duplicateNums);
    
    cout << "\nMerge nums with duplicateNums:\n";
    cout << "nums: ";
    nums.merge(duplicateNums);
    tools.printContainer(nums);
    cout << "duplicateNums: ";
    tools.printContainer(duplicateNums);
    
    cout << "\nReverse nums elements:\n";
    nums.reverse();
    tools.printContainer(nums);

    cout << "\nRemive all the elements from nums:\n";
    nums.clear();
    tools.printContainer(nums);

    return 0;
}
