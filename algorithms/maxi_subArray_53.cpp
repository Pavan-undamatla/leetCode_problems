#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// optimal approach

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int size = nums.size();
        int sum = 0;

        int max_val = INT_MIN;

        for (int i = 0; i < size; i++)
        {
            sum += nums[i];
            max_val = max(max_val, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return max_val;
    }
};

// better approach
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int size = nums.size();
        int sum = 0;
        int max_val = INT_MIN;

        for (int i = 0; i < size; i++)
        {
            sum = 0;
            for (int j = i; j < size; j++)
            {
                sum += nums[j];
                max_val = max(max_val, sum);

                if (sum < 0)
                {

                    break;
                }
            }
        }
        return max_val;
    }
};

// brute force approach

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int size = nums.size();
        int sum = 0;
        int max_val = INT_MIN;

        for (int i = 0; i < size; i++)
        {

            for (int j = i; j < size; j++)
            {
                sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }
                if (sum > max_val)
                {
                    max_val = sum;
                }
            }
        }
        cout << max_val << endl;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(nums) << endl;

    return 0;
}