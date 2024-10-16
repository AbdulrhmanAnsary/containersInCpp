#include <iostream>
#include <vector>

using namespace std;

// I used template like vectors to be able to use any data type.
template <typename E>
void printVector(E content, string end = "\n")
{
    // begin(): Returns a pointer indicating the first item in the vector.
    // end(): Returns a pointer indicating the location after the last element of the vector (not the last item, but the item that comes after it).
    for (auto element = content.begin(); element != content.end(); element++)
    {
        cout << *element << end;
    }
}

// I used a new template because each template belongs to what comes next only.
template <typename E>
void reversePrint(E content, string end = "\n")
{
    // rbegin(): It returns a reverse pointer indicating the last element of the vector.
    // rend(): Returns a pointer indicating the location before the first item on the vector.
    for (auto element = content.rbegin(); element != content.rend(); element++)
    {
        cout << *element << end;
    }
}

template <typename E>
void printByConstIterators(E content, string end = "\n")
{
    // cbegin() and cend() they are all like begin() and end() But they are used with vectors whose elements should not be modified. Returns const iterators.
    for (auto element = content.cbegin(); element != content.cend(); element++)
    {
        cout << *element << end;
    }
}

// begin(), end() or any function her they all returns an iterator object.

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3, 4, 5};

    printVector(nums);
    cout << "\nreverse print:\n";
    reversePrint(nums);

    // Change the first and the last element
    *nums.begin() = 9;
    // To change the last element we should make end() point to the last element instead of the next location after the last elemnt by subtract end() - 1.
    *(nums.end() - 1) = 7;
    cout << "\nAfter change the first and the last element:\n";
    printVector(nums);

    cout << "\nPrint by constant iterators:\n";
    printByConstIterators(nums);

    // If you run the below code you well see this error (cannot assign to return value because function 'operator*' returns a const value)
    // *nums.cbegin() = 33;
    // *(nums.cend() - 1) = 21;

    return 0;
}