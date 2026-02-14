#include <iostream>
#include <vector>
using namespace std;

// //    two pointer approach to find the length of longest continuous increasing subarray

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int n = nums.size();
        int max_val = 1;
        int count = 1;

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                count++;
            }
            else
            {
                max_val = max(max_val, count);
                count = 1;
            }
        }
        max_val = max(max_val, count);
        return max_val;
    }
};

//    sliding window approach to find the length of longest continuous increasing subarray

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {

        int n = nums.size();

        int left = 0;
        int max_len = 1;

        for (int right = 1; right < n; right++)
        {
            if (nums[right] > nums[right - 1])
            {
                max_len = max(max_len, right - left + 1);
            }
            else
            {
                left = right;
            }
        }

        return max_len;
    }
};

//   brute force approach to find the length of longest continuous increasing subarray

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int n = nums.size();
        int max_len = 1;

        for (int i = 0; i < n; i++)
        {
            int count = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[j - 1])
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            max_len = max(max_len, count);
        }

        return max_len;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 4, 7};
    cout << sol.findLengthOfLCIS(nums) << endl;
    return 0;
}