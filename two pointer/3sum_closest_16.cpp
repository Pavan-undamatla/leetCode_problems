// original leetcode    optimized approach

// class Solution
// {
// public:
//     int threeSumClosest(vector<int> &nums, int target)
//     {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int minDiff = INT_MAX;
//         int closestSum = 0;

//         for (int i = 0; i < n - 2; i++)
//         {
//             int j = i + 1;
//             int k = n - 1;

//             while (j < k)
//             {
//                 int sum = nums[i] + nums[j] + nums[k];
//                 int diff = abs(sum - target);

//                 if (diff < minDiff)
//                 {
//                     minDiff = diff;
//                     closestSum = sum;
//                 }

//                 if (sum < target)
//                     j++;
//                 else
//                     k--;
//             }
//         }
//         return closestSum;
//     }
// };

// test code

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    sort(nums.begin(), nums.end());

    int target = 1;
    int size = nums.size();
    int minDiff = INT_MAX;
    int closestSum = 0;

    for (int i = 0; i < size - 2; i++)
    {
        int j = i + 1;
        int k = size - 1;

        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            int diff = abs(sum - target);

            if (diff < minDiff)
            {
                minDiff = diff;
                closestSum = sum;
            }

            if (sum < target)
                j++;
            else
                k--;
        }
    }

    cout << closestSum;
}
