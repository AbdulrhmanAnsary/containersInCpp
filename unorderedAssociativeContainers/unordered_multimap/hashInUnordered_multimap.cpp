#include <iostream>
#include <unordered_map>

using namespace std;

// To determine how the items in the container we create from Class unordered_map will be arranged
class Hash
{
  public:
    // To compare the value of any item we want to add relative to the number of characters in it,
    // then the numbers that consist of one number are placed in Bucket,
    // and the numbers that consist of two numbers in Bucket are placed etc.
    size_t operator()(const string &key) const
    {
        return key.length(); // It determined in any bucket item will be added
    }
};

int main()
{
    unordered_multimap<string, string, Hash> um = {
        {"Egypt", "Giza"},
        {"Lebanon", "Beirut"},
        {"Syria", "Sweida"},
        {"Lebanon", "Tripolie"},
        {"Syria", "Idlib"},
        {"KSA", "Riyadh"},
        {"Egypt", "Cairo"},
        {"Lebanon", "Sidon"},
        {"Syria", "Damascus"},
        {"KSA", "Makkah"},
        {"Syria", "Homs"},
        {"Algeria", "Algiers"}};

    int totalBuckets = um.bucket_count();

    for (int i = 0; i < totalBuckets; i++)
    {
        cout << "bucket[" << i << "] elements:";
        for (auto it = um.begin(i); it != um.end(i); ++it)
        {
            cout << " [" << it->first << " : " << it->second << "]";
        }

        cout << endl;
    }

    return 0;
}