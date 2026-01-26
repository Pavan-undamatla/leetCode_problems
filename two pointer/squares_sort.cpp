//  optimized leetcode solution:

// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int size = nums.size();
//         vector<int> my_ary(size);

//         int start = 0;
//         int end = size - 1;
//         int index = size - 1;

//         while (start <= end) {
//             if (abs(nums[start]) <= abs(nums[end])) {
//                 my_ary[index--] = nums[end] * nums[end];
//                 end--;
//             } else {
//                 my_ary[index--] = nums[start] * nums[start];
//                 start++;
//             }
//         }

//         return my_ary;
//     }
// };

//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int array[] = {-10, -4, -2, 0, 3, 5, 6};
    int size = sizeof(array) / sizeof(array[0]);

    int start = 0;
    int end = size - 1;
    int index = size - 1; // result array index
    int my_ary[size];

    while (start <= end)
    {
        if (abs(array[start]) <= abs(array[end]))
        {
            my_ary[index--] = array[end] * array[end];
            end--;
        }
        else
        {
            my_ary[index--] = array[start] * array[start];
            start++;
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << my_ary[i] << " ";
    }
}
