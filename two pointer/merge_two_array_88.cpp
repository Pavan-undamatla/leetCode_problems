//    original leetcode problem

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m + n - 1;
        int k = m - 1;
        int j = n - 1;

        while (k >= 0 && j >= 0)
        {
            if (nums1[k] < nums2[j])
            {
                nums1[i--] = nums2[j--];
            }
            else
            {
                nums1[i--] = nums1[k--];
            }
        }

        while (j >= 0)
        {
            nums1[i--] = nums2[j--];
        }
    }
};

// test code

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    int i = m - 1;     // Pointer for nums1
    int j = n - 1;     // Pointer for nums2
    int k = m + n - 1; // Pointer for merged array

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }

    // If there are remaining elements in nums2
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }

    // Print the merged array
    for (int num : nums1)
    {
        cout << num << " ";
    }

    return 0;
}