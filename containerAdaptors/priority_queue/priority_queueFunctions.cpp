#include <iostream>
#include <queue>

using namespace std;

template <typename T>
void print_priority_queue(const priority_queue<T> &container)
{
    // A temporary priority_queue to print all elements
    priority_queue<T> temp = container;

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    // A priority_queue automatically sorts elements in descending order by default.
    // The element with the highest value is at the top (accessible using top()).
    priority_queue<int> nums;
    priority_queue<int> oddNums;
    priority_queue<string> fruits;

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

    fruits.push("Apple");
    fruits.push("Banana");
    fruits.push("Blueberry");
    fruits.push("Strawberry");

    cout << "nums: ";
    print_priority_queue(nums);
    cout << "oddNums: ";
    print_priority_queue(oddNums);
    cout << "fruits: ";
    print_priority_queue(fruits);

    cout << "\nIs nums empty: ";
    cout << nums.empty() << endl;

    cout << "nums size: ";
    cout << nums.size() << endl;

    cout << "\nThe element with the highest priority: ";
    cout << nums.top() << endl;

    cout << "\nAdd a new element to nums:\n";
    nums.emplace(11);
    print_priority_queue(nums);

    cout << "\nRemove the top element from nums:\n";
    nums.pop();
    print_priority_queue(nums);

    cout << "\nAfter using swap():\n";
    nums.swap(oddNums);
    cout << "nums: ";
    print_priority_queue(nums);
    cout << "oddNums: ";
    print_priority_queue(oddNums);

    return 0;
}