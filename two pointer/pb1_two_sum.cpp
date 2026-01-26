

// // optimized leetcode solution
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> mp;
//         vector<int> ans;
//         for (int i = 0; i < nums.size(); i++) {
//             int first_num = nums[i];
//             int second_num = target - first_num;
//             if (mp.find(second_num) != mp.end()) {
//                 ans.push_back(mp[second_num]);
//                 ans.push_back(i);
//                 return ans;
//             }
//             mp[first_num] = i;
//         }
//         return ans;
//     }
// };

//                          better approach using two pointers

#include <iostream>
using namespace std;

void two_sum(int array[], int target, int end)
{
    int start = 0;
    int n = end;
    while (start < end)
    {
        if (array[start] + array[end] == target)
        {
            cout << "[" << start << "," << end << "]";
            return;
        }
        end--;
        if (start == end)
        {
            start++;
            end = n;
        }
    }
}
int main()
{
    int array[] = {2, 3, 4, 5, 6, 9};
    int size = sizeof(array) / sizeof(array[0]) - 1;
    two_sum(array, 9, size);
}