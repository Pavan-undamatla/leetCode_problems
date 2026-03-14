#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

// Optimized approach

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            // remove indexes outside window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // remove smaller elements
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            // window formed
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};

// Brute force approach

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        int n = nums.size();

        for (int i = 0; i <= n - k; i++)
        {
            int max_val = nums[i];
            for (int j = i; j < i + k; j++)
            {
                max_val = max(max_val, nums[j]);
            }
            res.push_back(max_val);
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = s.maxSlidingWindow(nums, k);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}