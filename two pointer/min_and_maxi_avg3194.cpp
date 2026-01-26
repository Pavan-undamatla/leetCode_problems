//  original leet code

// class Solution {
// public:
//     double minimumAverage(vector<int>& nums) {

//         double ans=DBL_MAX;
//         int size=nums.size();
//         sort(nums.begin(),nums.end());
//         int left=0,right=size-1;

//         while(left<right){

//         int maxi=nums[right];
//         int mini=nums[left];

//         double value=(maxi+mini)/2.0f;
//         ans=min(ans,value);
//         left++;
//         right--;
//         }
//     return ans;

//     }
// };

// test code

#include <iostream>
using namespace std;
#include <algorithm>
#include <cfloat>
#include <vector>

int main()
{
    int array[] = {7, 8, 3, 4, 15, 13, 4, 1};
    double ans = DBL_MAX;
    int size = sizeof(array) / sizeof(array[0]);
    vector<double> avg;
    sort(array, array + size);
    int i = 0, j = size - 1;
    while (i < j)
    {
        double average = (array[i] + array[j]) / 2.0;
        avg.push_back(average);
        ans = min(ans, average);
        i++;
        j--;
    }
    cout << ans;
}

//   burter approach

// float mini_max_avg(int array[], int size)
// {
//     vector<float> avg;
//     int maxi_indx = 0;
//     int mini_indx = 0;
//     while (size > 1)
//     {
//         int maxi = array[0];
//         int mini = array[0];

//         for (int i = 0; i < size; i++)
//         {
//             if (maxi < array[i])
//             {
//                 maxi = array[i];
//                 maxi_indx = i;
//             }
//             if (mini > array[i])
//             {
//                 mini = array[i];
//                 mini_indx = i;
//             }
//         }
//         float average = (float)(maxi + mini) / 2;
//         avg.push_back(average);

//         // Remove maxi element
//         array[maxi_indx] = array[size - 1];
//         size--;

//         // Adjust mini_indx if it was pointing to last element
//         if (mini_indx == size)
//             mini_indx = maxi_indx;

//         // Remove mini element
//         array[mini_indx] = array[size - 1];
//         size--;
//     }

//     float ans = avg[0];
//     for (float x : avg)
//     {
//         cout << x << " ";

//         ans = min(ans, x);
//     }

//     return ans;
// }

// int main()
// {
//     int array[] = {7, 8, 3, 4, 15, 13, 4, 1};
//     int size = sizeof(array) / sizeof(array[0]);
//     cout << "avg mini value is " << mini_max_avg(array, size);
// }
