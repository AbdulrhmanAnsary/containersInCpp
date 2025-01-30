#include <iostream>
#include <queue>

using namespace std;

void printQueue(const queue<int> &nums)
{
    // A temporary queue
    queue<int> temp = nums;

    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    // The method of storing the items in this container is based on the FIFO method,
    // which is an abbreviation for the phrase First In First Out.
    queue<int> nums;
    queue<int> oddNums;

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
    printQueue(nums);
    cout << "oddNums: ";
    printQueue(oddNums);

    cout << "\nIs the nums empty: ";
    cout << nums.empty() << endl;

    cout << "nums size: ";
    cout << nums.size() << endl;

    cout << "The first element in nums: ";
    cout << nums.front() << endl;

    cout << "The last element in nums: ";
    cout << nums.back() << endl;

    cout << "\nChange the first element in nums:\n";
    nums.front() = 2;
    printQueue(nums);

    cout << "\nChange the last element in nums:\n";
    nums.back() = 8;
    printQueue(nums);

    cout << "\nAdd a new element to nums:\n";
    nums.emplace(11);
    printQueue(nums);

    cout << "\nRemove the first element from nums:\n";
    nums.pop();
    printQueue(nums);

    cout << "\nAfter using swap():\n";
    nums.swap(oddNums);
    cout << "nums: ";
    printQueue(nums);
    cout << "oddNums: ";
    printQueue(oddNums);

    return 0;
}