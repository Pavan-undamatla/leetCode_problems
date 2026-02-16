#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//   optimized approach using two pointer technique

class Solution
{
public:
    int longMountain(vector<int> &nums)
    {
        int size = nums.size();
        int max_val = 0;
        int i = 1;

        while (i < size - 1)
        {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            {
                int left = i;
                int right = i;

                while (left > 0 && nums[left] > nums[left - 1])
                    left--;

                while (right < size - 1 && nums[right] > nums[right + 1])
                    right++;

                max_val = max(max_val, right - left + 1);

                i = right;
            }
            else
            {
                i++;
            }
        }

        return max_val;
    }
};

//    better approach using brute force

int longMountain(vector<int> &nums)
{
    int n = nums.size();
    int maxLen = 0;

    for (int i = 0; i < n - 2; i++)
    {
        int j = i;

        // climb up
        while (j < n - 1 && nums[j] < nums[j + 1])
            j++;

        // must have climbed at least once
        if (j == i)
            continue;

        int peak = j;

        // go down
        while (j < n - 1 && nums[j] > nums[j + 1])
            j++;

        // must have descended
        if (j > peak)
        {
            maxLen = max(maxLen, j - i + 1);
        }
    }

    return maxLen;
}

//   brute force approach

class Solution
{
public:
    int longMountain(vector<int> &nums)
    {
        int max_len = 0;
        int size = nums.size();

        for (int i = 0; i < size; i++)
        {

            for (int j = i + 2; j < size; j++)
            {
                bool increasing = false;
                bool decreasing = false;
                int k = i;

                while (k < j && nums[k] < nums[k + 1])
                {
                    increasing = true;
                    k++;
                }

                while (k < j && nums[k] > nums[k + 1])
                {
                    decreasing = true;
                    k++;
                }
                if (k == j && increasing && decreasing)
                {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        return max_len;
    }
};
int main()
{
    vector<int> nums = {2, 1, 4, 7, 3, 2, 1, 5};
    Solution s;
    cout << s.longMountain(nums) << endl;
    return 0;
}
