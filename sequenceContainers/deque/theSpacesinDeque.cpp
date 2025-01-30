#include <iostream>
#include <deque>

using namespace std;

template <typename T>
void printDeque(deque<T> &array)
{
    cout << "{";
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i];
        if (i < array.size() - 1)
            cout << ", ";
    }
    cout << "}\n";
}

int main(int argc, char *argv[])
{
    deque<int> nums;

    cout << "Empty: " << nums.empty() << endl;
    cout << "Size " << nums.size() << endl;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);

    cout << "\nAfter push_back():\n";
    printDeque(nums);
    cout << "Empty: " << nums.empty() << endl;
    cout << "Size: " << nums.size() << endl;
    cout << "Max size: " << nums.max_size() << endl;

    nums.resize(10);
    cout << "\nAfter resize():\n";
    cout << "Empty: " << nums.empty() << endl;
    cout << "Size: " << nums.size() << endl;
    cout << "Max size: " << nums.max_size() << endl;

    // Reduce capacity to actual size
    nums.shrink_to_fit();

    cout << "\nAfter shrink:\n";
    printDeque(nums);

    return 0;
}