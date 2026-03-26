#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// optimal approach

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_set<int> set;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {

            if (set.find(nums[i]) == set.end())
            {
                set.insert(nums[i]);
            }
            else
            {
                return nums[i];
            }
        }
        return -1;
    }
};

// better approach

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;

            if (freq[nums[i]] > 1)
            {
                return nums[i];
            }
        }
        return -1;
    }
};

//  brute force approach

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 4, 2, 9, 6, 7, 5, 8, 9};
    cout << s.findDuplicate(nums) << endl;
    return 0;
}