#include <iostream>
#include <array>

using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        array<int, 5> nums;
        array<int, 5> nums2 = {9, 6, 3, 7, 5};

        nums.fill(0);
        nums.swap(nums2);
        nums[0] = 17;
        nums[nums.size() - 1] = 33;

        cout << "At 0: " << nums.at(0) << endl;
        cout << "Empry: " << nums.empty() << endl;
        cout << "Size: " << nums.size() << endl;

        if (!nums.empty())
        {
            cout << "Front: " << nums.front() << endl;
            cout << "Back: " << nums.back() << endl;
        }

        cout << "array elements : ";
        for (size_t i = 0; i < nums.size(); i++)
        {
            cout << nums.at(i) << ", ";
        }
    }
    catch (...)
    {
        perror("ArrayError");
    }

    return 0;
}