#include <iostream>
#include <forward_list>

using namespace std;

template <typename T>
void printForward_list(forward_list<T> &array)
{
    cout << "{";
    for (auto item = array.begin(); item != array.end(); item++)
    {
        cout << *item;
        if (next(item) != array.end())
            cout << ", ";
    }
    cout << "}\n";
}

int main(int argc, char *argv[])
{
    forward_list<int> nums = {10, 20, 30, 40, 50};

    cout << "Empty: " << nums.empty() << endl;
    cout << "Max size: " << nums.max_size() << endl;
    printForward_list(nums);

    nums.resize(10);

    cout << "\nAfter resize():\n";
    cout << "Empty: " << nums.empty() << endl;
    cout << "Max size: " << nums.max_size() << endl;
    printForward_list(nums);

    return 0;
}
