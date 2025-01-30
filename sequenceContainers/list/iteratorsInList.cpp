#include <iostream>
#include <list>

using namespace std;

// I used template like vectors to be able to use any data type.
template <typename E>
void printList(E content, string end = "\n")
{
    // begin(): Returns a pointer indicating the first item in the list.
    // end(): Returns a pointer indicating the location after the last element of the list (not the last item, but the item that comes after it).
    for (auto element = content.begin(); element != content.end(); element++)
    {
        cout << *element << end;
    }
}

// I used a new template because each template belongs to what comes next only.
template <typename E>
void reversePrint(E content, string end = "\n")
{
    // rbegin(): It returns a reverse pointer indicating the last element of the list.
    // rend(): Returns a pointer indicating the location before the first item on the list.
    for (auto element = content.rbegin(); element != content.rend(); element++)
    {
        cout << *element << end;
    }
}

template <typename E>
void printByConstIterators(E content, string end = "\n")
{
    // cbegin() and cend() they are all like begin() and end() But they are used with the lists whose elements should not be modified. Returns const iterators.
    for (auto element = content.cbegin(); element != content.cend(); element++)
    {
        cout << *element << end;
    }
}

// begin(), end() or any function her they all returns an iterator object.

int main(int argc, char *argv[])
{
    list<int> nums = {1, 2, 3, 4, 5};

    printList(nums);
    cout << "\nReverse print:\n";
    reversePrint(nums);

    cout << "\nChange the first element using begin():\n";
    *nums.begin() = 9;
    // *nums.end() = 7; This is wrong because it's returns a pointer indicating the location that comes after the last item on the list (this site has no value).
    printList(nums);
    
    cout << "\nChange the first and the last element using front(), back():\n";
    nums.front() = 13;
    nums.back() = 20;
    printList(nums);
    
    cout << "\n*nums.begin() = " << *nums.begin() << endl;
    cout << "nums.front() = " << nums.front() << endl;
    // cout << "*nums.end() = " << *nums.end() << endl; leads to unexpected behavior.
    cout << "nums.back() = " << nums.back() << endl;

    cout << "\nPrint by constant iterators:\n";
    printByConstIterators(nums);

    // If you run the below code you well see this error (cannot assign to return value because function 'operator*' returns a const value)
    // *nums.cbegin() = 33;
    // *(nums.cend() - 1) = 21;

    return 0;
}