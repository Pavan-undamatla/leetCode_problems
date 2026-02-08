//  optimized approach using hash map to find pairs that sum up to k

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxoperation(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp; // value -> frequency

        int count = 0;

        for (int x : arr)
        {
            int need = k - x;

            // check if complementary value exists
            if (mp[need] > 0)
            {
                mp[need]--; // use one occurrence  count is reduced by 1
                count++;
            }
            else
            {
                mp[x]++; // store current element in the map count is increased by 1
            }
        }

        return count;
    }
};

// better approach using two pointers after sorting the array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxoperation(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());

        int i = 0, j = arr.size() - 1;
        int count = 0;

        while (i < j)
        {
            int sum = arr[i] + arr[j];

            if (sum == k)
            {
                count++;
                i++; // move left pointer
                j--; // move right pointer
            }
            else if (sum < k)
            {
                i++; // need a bigger sum
            }
            else
            {
                j--; // need a smaller sum
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 3, 3, 4, 3, 5};
    int k = 7;

    cout << sol.maxoperation(arr, k) << endl;
}