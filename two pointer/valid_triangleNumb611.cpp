#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//          optimized approach by using two pointer technique ans sorting the array
class solution
{
public:
    int threeTriangle(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int count = 0;

        for (int k = size - 1; k >= 2; k--)
        {
            int i = 0;
            int j = k - 1;
            while (i < j)
            {
                if (nums[i] + nums[j] > nums[k])
                {
                    count += (j - i);
                    j--;
                }
                else
                {
                    i++;
                }
            }
        }
        return count;
    }
};

// burte force approach

class solution
{
public:
    int threeTriangle(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] + nums[j] > nums[k])
                        count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    solution sol;
    vector<int> nums = {2, 2, 3, 4};
    int result = sol.threeTriangle(nums);
    cout << "Number of valid triangles: " << result << endl;
    return 0;
}
