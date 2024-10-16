#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vector)
{
    for (int element : vector)
        cout << element << " ";
    cout << endl;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3};
    vector<int> evenNums = {2, 4, 6, 8};

    printVector(nums);

    cout << "\nAfter assign:\n";
    nums.assign(5, 9);
    printVector(nums);

    cout << "\nAfter push_back:\n";
    nums.push_back(7);
    printVector(nums);

    cout << "\nAfter pop_back:\n";
    nums.pop_back();
    printVector(nums);

    cout << "\nAfter swap:\n";
    nums.swap(evenNums);
    printVector(nums);

    cout << "\nAfter insert:\n";
    auto insertPosition = nums.insert(nums.begin() + 3, 5);
    printVector(nums);

    cout << "\nAfter erase for one item:\n";
    nums.erase(nums.begin() + 1);
    printVector(nums);

    cout << "\nAfter erase for Several items:\n";
    nums.erase(nums.begin() + 1, insertPosition);
    printVector(nums);

    cout << "\nAfter clear:\n";
    nums.clear();
    printVector(nums);

    return 0;
}