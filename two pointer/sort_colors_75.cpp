#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        int mid = 0;
        while (mid <= high)
        {

            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        return;
    }
};

//  better approach
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
    }
};

// //  brute force approach
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            j = i - 1;
            while (j >= 0 && nums[j] >= nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                j--;
            }
        }
    }
};

int main()
{
    vector<int> nums = {2, 0, 1, 0, 1, 2};
    Solution s;
    s.sortColors(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}