#include <iostream>
#include <unordered_set>

using namespace std;

// To determine how the items in the container we create from Class Unordered_Set will be arranged
class Hash
{
  public:
    // To compare the value of any item we want to add relative to the number of characters in it,
    // then the numbers that consist of one number are placed in Bucket,
    // and the numbers that consist of two numbers in Bucket are placed etc.
    size_t operator()(const int &val) const
    {
        int num = val;
        int digits = 1; // To calculate the number of numbers in Val

        while (num != 0)
        {
            digits++;
            num = num / 10;
        }

        return digits; // It determined in any bucket item will be added
    }
};

int main()
{
    unordered_set<int, Hash> nums = {6, 34, 72, 3, 1, 123, 55, 3, 100, 2020};

    for (int i = 0; i < nums.bucket_count(); i++)
    {
        cout << "bucket[" << i << "] elements:";
        for (auto it = nums.begin(i); it != nums.end(i); ++it)
            cout << " " << *it;
        cout << endl;
    }

    return 0;
}