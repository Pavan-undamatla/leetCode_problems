#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//   optimized approach using two pointer technique

class Solution
{
public:
    // Counts number of pairs with sum <= comp
    long long countAtMost(vector<int> &nums, long long comp)
    {
        long long ans = 0;
        int j = nums.size() - 1;

        for (int i = 0; i < j; i++)
        {
            while (i < j && nums[i] + nums[j] > comp)
            {
                j--;
            }
            ans += (j - i);
        }
        return ans;
    }

    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        return countAtMost(nums, upper) - countAtMost(nums, lower - 1);
    }
};

//  better approach using binary search

class solution
{
public:
    long long countFairpairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        long long count = 0;

        for (int i = 0; i < size - 1; i++)
        {
            int left = lower - nums[i];
            int right = upper - nums[i];
            int leftIndex = lower_bound(nums.begin() + i + 1, nums.end(), left) - nums.begin();
            int rightIndex = upper_bound(nums.begin() + i + 1, nums.end(), right) - nums.begin();
            count += (rightIndex - leftIndex);
        }
        return count;
    }
};

//   brute force approach

class solution
{
public:
    long long countFairpairs(vector<int> &nums, int lower, int upper)
    {
        int size = nums.size();
        int count = 0;

        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                int sum = nums[i] + nums[j];

                if (lower <= sum && sum <= upper)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    solution obj;
    vector<int> nums = {0, 1, 7, 4, 4, 5};
    int lower = 3;
    int upper = 6;
    long long result = obj.countFairpairs(nums, lower, upper);
    cout << "Count of Fair Pairs: " << result << endl;
    return 0;
}
