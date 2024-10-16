#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVector(vector<T> &array)
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
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);

    cout << "Empty: " << nums.empty() << endl;
    cout << "Size: " << nums.size() << endl;
    cout << "Capacity: " << nums.capacity() << endl;
    cout << "Max size: " << nums.max_size() << endl;

    nums.resize(10);
    cout << "\nAfter resize():\n";
    cout << "Empty: " << nums.empty() << endl;
    cout << "Size: " << nums.size() << endl;
    cout << "Capacity: " << nums.capacity() << endl;
    cout << "Max size: " << nums.max_size() << endl;

    // Reduce capacity to actual size
    nums.shrink_to_fit();
    
    cout << "\nAfter shrink:\n";
    cout << "Capacity: " << nums.capacity() << endl;
    printVector(nums);

    return 0;
}