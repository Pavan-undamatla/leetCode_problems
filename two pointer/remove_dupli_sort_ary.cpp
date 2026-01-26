// original leetcode code

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         if (nums.size() == 0) return 0;

//         int i = 0;
//         int j = 1;
//         int size = nums.size();

//         while (j < size) {
//             if (nums[i] != nums[j]) {
//                 i++;
//                 nums[i] = nums[j];
//             }
//             j++;
//         }
//         return i + 1;
//     }
// };

// Test code

#include <iostream>
using namespace std;

int main()
{
    // slow and fast pointer
    int array[] = {1, 2, 2, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]) - 1;
    int i = 0, j = 1;
    while (j <= size)
    {
        if (array[i] != array[j])
        {
            swap(array[i + 1], array[j]);
            i++;
        }
        j++;
    }
    for (int i = 0; i <= size; i++)
    {
        cout << array[i] << " ";
    }
    cout << i;
}