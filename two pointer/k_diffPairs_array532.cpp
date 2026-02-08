#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int count = 0;

        for (int x1 : nums)
        {
            mp[x1]++;
        }

        for (auto x : mp)
        {
            int target = x.first + k;

            if (k == 0)
            {
                if (x.second > 1)
                {
                    count++;
                }
            }
            else if (mp.find(target) != mp.end())
            {

                count++;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;
    cout << s.findPairs(nums, k) << endl; // Output: 2
    return 0;
}
