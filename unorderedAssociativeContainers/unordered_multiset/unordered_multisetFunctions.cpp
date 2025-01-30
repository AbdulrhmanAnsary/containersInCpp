#include <iostream>
#include <unordered_set>

using namespace std;

// Function to print the contents of an unordered_multiset
template <typename T>
void printUnordered_multiset(const unordered_multiset<T> &container)
{
    cout << "{";
    for (auto item = container.begin(); item != container.end(); ++item)
    {
        cout << *item;
        if (next(item) != container.end())
            cout << ", ";
    }
    cout << "}\n";
}

// Function to print elements in specific buckets
template <typename T>
void printBuckets(const unordered_multiset<T> &container, int bucketStart, int bucketEnd)
{
    // bucketStart: the bucket number to start from.
    // bucketEnd: the bucket number to stop at.
    cout << "{";
    bool isFirst = true; // To handle commas correctly
    for (int bucketNum = bucketStart; bucketNum <= bucketEnd; ++bucketNum)
    {
        for (auto item = container.begin(bucketNum); item != container.end(bucketNum); ++item)
        {
            if (!isFirst)
                cout << ", ";
            cout << *item;
            isFirst = false;
        }
    }
    cout << "}\n";
}

int main()
{
    unordered_multiset<int> nums = {4, 3, 2, 1, 4, 1, 5, 2}; // Duplicate values will be removed automatically
    unordered_multiset<int> oddNums = {1, 3, 5, 7, 9, 11};

    // Print all elements in 'nums'
    cout << "nums:\n";
    printUnordered_multiset(nums);

    // Print elements in buckets 1 to 3
    cout << "Print nums from second bucket to the third bucket\n";
    printBuckets(nums, 1, 3);

    // Display properties of the unordered_set
    cout << "\nIs nums empty: " << (nums.empty() ? "Yes" : "No") << endl;
    cout << "nums size: " << nums.size() << endl;
    cout << "The max size of elements count: " << nums.max_size() << endl;
    cout << "The bucket count in nums: " << nums.bucket_count() << endl;
    cout << "The third bucket size: " << nums.bucket_size(2) << endl;
    cout << "The max bucket count: " << nums.max_bucket_count() << endl;
    cout << "The index of bucket depending on its value: " << nums.bucket(5) << endl;

    // Add a new element to nums using emplace
    cout << "\nAdd new element to nums using emplace:\n";
    nums.emplace(6);
    printUnordered_multiset(nums);

    // Check if a specific value is in nums
    cout << "\nIs the number '9' in nums: " << (nums.count(9) ? "Yes" : "No") << endl;

    // Find a specific element in nums
    auto it = nums.find(5);
    if (it != nums.end())
        cout << "Find the number '5' in nums: " << *it << endl;
    else
        cout << "The number '5' was not found in nums.\n";

    // Find the range of equal elements using equal_range
    auto result = nums.equal_range(2);
    if (result.first != nums.end())
        cout << "Element found: " << *(result.first) << "\n";
    else
        cout << "Element not found.\n";

    // Remove the first element in nums
    cout << "\nRemove the first element in nums:\n";
    nums.erase(nums.begin());
    printUnordered_multiset(nums);

    // Remove elements in a specific range
    cout << "\nRemove from 2 to 3 in nums:\n";
    auto four = nums.find(4);
    nums.erase(nums.find(2), four);
    printUnordered_multiset(nums);

    // Swap elements between nums and oddNums
    cout << "\nSwapping nums with oddNums:\n";
    nums.swap(oddNums);
    cout << "nums: ";
    printUnordered_multiset(nums);
    cout << "oddNums: ";
    printUnordered_multiset(oddNums);

    return 0;
}