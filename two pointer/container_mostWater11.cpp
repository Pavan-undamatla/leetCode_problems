#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//  optimized approach using two pointer technique

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int size = height.size();
        int left = 0;
        int right = size - 1;
        int max_area = 0;

        while (left < right)
        {
            int area = (right - left) * min(height[left], height[right]);
            max_area = max(max_area, area);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return max_area;
    }
};

//  brute force approach

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int max_area = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                int area = (j - i) * min(height[i], height[j]);
                max_area = max(max_area, area);
            }
        }
        return max_area;
    }
};

int main()
{
    Solution s;
    vector<int> height = {2, 3, 4, 5, 18, 19, 2, 1, 17, 1, 6};
    cout << s.maxArea(height) << endl;
    return 0;
}