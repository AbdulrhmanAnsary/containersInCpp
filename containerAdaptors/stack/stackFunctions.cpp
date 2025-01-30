#include <iostream>
#include <stack>

using namespace std;

void printStack(const stack<int> &nums)
{
    // A temporary copy
    stack<int> temp = nums;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    // The method of storing the items in this container is based on the LiFo method,
    // which is an abbreviation for the phrase Last In First Out.
    stack<int> nums;
    stack<int> oddNums;

    nums.push(5);
    nums.push(9);
    nums.push(3);
    nums.push(7);
    nums.push(6);

    oddNums.push(1);
    oddNums.push(3);
    oddNums.push(5);
    oddNums.push(7);
    oddNums.push(9);

    cout << "nums: ";
    printStack(nums);
    cout << "oddNums: ";
    printStack(oddNums);

    cout << "\nIs the nums empty: ";
    cout << nums.empty() << endl;

    cout << "nums size: ";
    cout << nums.size() << endl;

    cout << "The last element in nums: ";
    cout << nums.top() << endl;

    cout << "\nChange the last element in nums:\n";
    nums.top() = 2;
    printStack(nums);

    cout << "\nAdd a new element to nums:\n";
    nums.emplace(11);
    printStack(nums);

    cout << "\nRemove the last element from nums:\n";
    nums.pop();
    printStack(nums);

    cout << "\nAfter using swap():\n";
    nums.swap(oddNums);
    cout << "nums: ";
    printStack(nums);
    cout << "oddNums: ";
    printStack(oddNums);

    return 0;
}