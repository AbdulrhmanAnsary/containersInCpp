#include <iostream>
#include <forward_list>

using namespace std;

void printArray(forward_list<int> &nums)
{
    for (auto num = nums.begin(); num != nums.end(); num++)
        cout << *num << " ";
    cout << endl;
}

int main(int argc, char *argv[])
{
    forward_list<int> nums = {1, 2, 3, 4, 5, 6, 7};

    cout << "The first element: " << *nums.begin() << endl;

    cout << "nums: ";
    printArray(nums);

    cout << "Add new number at the beginning:\n";
    nums.insert_after(nums.before_begin(), 8); // Insert before the first element

    cout << "nums: ";
    printArray(nums);

    return 0;
}
