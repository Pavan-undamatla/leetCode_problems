
//  optimized approach using hash map

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> mp;
        int count = 0;

        for (int a : nums1)
        {
            for (int b : nums2)
            {
                mp[a + b]++;
            }
        }
        for (int c : nums3)
        {
            for (int d : nums4)
            {

                int target = -(c + d);
                if (mp.find(target) != mp.end())
                {
                    count += mp[target];
                }
            }
        }
        return count;
    }
};

//  test code for 4sum ii problem

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> mp;
        int count = 0;

        for (int a : nums1)
        {
            for (int b : nums2)
            {
                mp[a + b]++;
            }
        }
        for (int c : nums3)
        {
            for (int d : nums4)
            {

                int target = -(c + d);
                if (mp.find(target) != mp.end())
                {
                    count += mp[target];
                }
            }
        }
        return count;
    }
};
int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, -1, -4};
    vector<int> nums2 = {1, -2, 4, -5};
    vector<int> nums3 = {2, -2, -3, 5};
    vector<int> nums4 = {1, -5, 4, -5};

    cout << sol.fourSumCount(nums1, nums2, nums3, nums4) << endl; // Output: 2
}

//  brute force approach

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     vector<int> nums1 = {1, 2, -1, -4};
//     vector<int> nums2 = {1, -2, 4, -5};
//     vector<int> nums3 = {2, -2, -3, 5};
//     vector<int> nums4 = {1, -5, 4, -5};

//     int target = 0;
//     int count = 0;

//     for (int i = 0; i < nums1.size(); i++)
//     {
//         for (int j = 0; j < nums2.size(); j++)
//         {
//             for (int k = 0; k < nums3.size(); k++)
//             {
//                 for (int l = 0; l < nums4.size(); l++)
//                 {
//                     if (nums1[i] + nums2[j] + nums3[k] + nums4[l] == target)
//                     {
//                         count++;
//                     }
//                 }
//             }
//         }
//     }
//     cout << count << endl; // Output: 2
// }
