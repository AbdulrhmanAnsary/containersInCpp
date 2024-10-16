#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3, 4, 5};

    cout << "The second element = " << nums.at(1) << endl;

    // Change the second element
    nums.at(1) = 6;
    cout << "After update = " << nums.at(1) << endl;

    // Change the first element
    nums.front() = 7;
    cout << "The first element = " << nums.front() << endl;

    // Change the last element
    nums.back() = 9;
    cout << "The last element = " << nums.back() << endl;

    // Return a pointer for the first element
    cout << "\nThe first element pointer:\n";
    cout << nums.data() << endl;

    cout << "\nThe first element value:\n";
    cout << *nums.data() << endl;

    cout << "\nnums = ";
    for (int element : nums)
        cout << element << " ";

    return 0;
}