class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right)
        {

            if (nums[left] % 2 == 0)
            {
                left++;
            }
            else if (nums[right] % 2 != 0)
            {
                right--;
            }
            else
            {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        return nums;
    }
};

//  test code

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {3, 1, 2, 4};

    int left = 0, right = nums.size() - 1;

    while (left < right)
    {
        if (nums[left] % 2 > nums[right] % 2)
        {
            swap(nums[left], nums[right]);
        }

        if (nums[left] % 2 == 0)
            left++;

        if (nums[right] % 2 == 1)
            right--;
    }

    for (int num : nums)
        cout << num << " ";

    return 0;
}
