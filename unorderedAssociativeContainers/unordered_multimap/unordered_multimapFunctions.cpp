#include <iostream>
#include <unordered_map>

using namespace std;

template <typename key, typename T>
void printUnordered_map(const unordered_multimap<key, T> &container)
{
    cout << "{";
    for (auto item = container.begin(); item != container.end(); item++)
    {
        cout << item->first << " : " << item->second;
        if (next(item) != container.end())
            cout << ", ";
    }
    cout << "}\n";
}

// Function to print elements in specific buckets
template <typename key, typename T>
void printBuckets(const unordered_multimap<key, T> &container, int bucketStart, int bucketEnd)
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
            cout << item->first << " : " << item->second;
            isFirst = false;
        }
    }
    cout << "}\n";
}

int main(int argc, char *argv[])
{
    unordered_multimap<int, string> nums = {{4, "four"}, {3, "three"}, {1, "first one"}, {2, "two"}, {1, "one"}, {5, "five"}};
    unordered_multimap<int, string> oddNums = {{1, "one"}, {3, "three"}, {5, "five"}, {7, "seven"}, {9, "nine"}, {11, "eleven"}};

    // Print all elements in 'nums'
    cout << "nums:\n";
    printUnordered_map(nums);

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

    cout << "\nAdd '8' to nums using insert:\n";
    nums.insert({8, "eight"}); // A copy of the item that has been added returns, { } is a pair
    printUnordered_map(nums);

    cout << "\nAdd '16' to nums using implace:\n";
    nums.emplace(16, "sixteen"); // A copy of the item that has been added returns
    printUnordered_map(nums);

    cout << "\nRemove '3' from nums:\n";
    nums.erase(3);
    printUnordered_map(nums);

    cout << "\nRemove the first element from nums:\n";
    nums.erase(nums.begin());
    printUnordered_map(nums);

    cout << "\nIs the number '9' in nums: " << nums.count(9) << endl;
    cout << "Is the number '2' in nums: " << nums.count(2) << endl;

    auto it = nums.find(5); // Return an object 'iterator' that refers to the item's address in memory, The object will equal end() value if isn't exist.
    if (it != nums.end())
        cout << "Find the number '5' in nums: " << it->second << endl;
    else
        cout << "The number '5' was not found in nums.\n";

    it = nums.find(22);
    if (it != nums.end())
        cout << "Find the number '22' in nums: " << it->second << endl;
    else
        cout << "The number '22' was not found in nums.\n";

    cout << "\nRemove a range from '16' to '2' in nums:\n";
    auto start = nums.find(16);                                    // The start of range
    unordered_multimap<int, string>::const_iterator end = nums.find(2); // The end of range
    if (start != nums.end() && end != nums.end())
        nums.erase(start, end); // Deletion will be stopped at "end"
    printUnordered_map(nums);

    cout << "\nSwapping nums with oddNums:\n";
    nums.swap(oddNums);
    cout << "nums: ";
    printUnordered_map(nums);
    cout << "oddNums: ";
    printUnordered_map(oddNums);

    return 0;
}