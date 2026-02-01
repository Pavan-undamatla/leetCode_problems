//       original leetcode    optimized approach

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        int n = nums.size();

        // STEP 1: sort
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {

            // skip duplicate i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            // STEP 2: two pointers
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0)
                {
                    res.push_back({nums[i], nums[j], nums[k]});

                    // skip duplicate j and k
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (j < k && nums[k] == nums[k - 1])
                        k--;

                    j++;
                    k--;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return res;
    }
};

//  test code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res;
    int size = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < size - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue; // skip duplicates for i
        int left = i + 1;
        int right = size - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                res.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1])
                    left++; // skip duplicates for left
                while (left < right && nums[right] == nums[right - 1])
                    right--; // skip duplicates for right
                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    for (int m = 0; m < res.size(); m++)
    {
        for (int n = 0; n < res[m].size(); n++)
        {
            cout << res[m][n] << " ";
        }
        cout << endl;
    }
}

// //   burte force approach
// //  without sorting and removing duplicates

// int main()
// {
//     vector<int> nums = {-1, 0, 1, 2, -1, -4};
//     vector<vector<int>> res;
//     int size = nums.size();
//     int i = 0;
//     int j = i + 1;
//     int k = size - 1;

//     while (i != j && i != k)
//     {
//         while (j != k)
//         {
//             while (k != j)
//             {
//                 if (nums[i] + nums[j] + nums[k] == 0)
//                 {
//                     res.push_back({nums[i], nums[j], nums[k]});
//                 }
//                 k--;
//             }
//             j++;
//             k = size - 1;
//         }
//         i++;
//         j = i + 1;
//         k = size - 1;
//     }
//     for (int m = 0; m < res.size(); m++)
//     {
//         for (int n = 0; n < res[m].size(); n++)
//         {
//             cout << res[m][n] << " ";
//         }
//         cout << endl;
//     }
// }