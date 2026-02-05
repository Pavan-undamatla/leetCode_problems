//    optimized approach using frequency map

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> freq;

        for (int x : arr)
            freq[x]++;

        vector<int> keys;
        for (auto &p : freq)
            keys.push_back(p.first);
        sort(keys.begin(), keys.end());

        long long ans = 0;

        for (int i = 0; i < keys.size(); i++)
        {
            for (int j = i; j < keys.size(); j++)
            {
                int k = target - keys[i] - keys[j];
                if (k < keys[j])
                    continue;
                if (!freq.count(k))
                    continue;

                long long a = freq[keys[i]];
                long long b = freq[keys[j]];
                long long c = freq[k];

                if (keys[i] == keys[j] && keys[j] == k)
                    ans += a * (a - 1) * (a - 2) / 6;
                else if (keys[i] == keys[j])
                    ans += a * (a - 1) / 2 * c;
                else if (keys[j] == k)
                    ans += b * (b - 1) / 2 * a;
                else
                    ans += a * b * c;
            }
        }
        return ans % MOD;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int target = 8;
    cout << sol.threeSumMulti(arr, target) << endl; // Output: 20
    return 0;
}

//  better approach

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// class Solution
// {
// public:
//     int threeSumMulti(vector<int> &arr, int target)
//     {
//         const int MOD = 1e9 + 7;
//         sort(arr.begin(), arr.end());

//         int n = arr.size();
//         long long count = 0;

//         for (int i = 0; i < n - 2; i++)
//         {
//             int left = i + 1, right = n - 1;

//             while (left < right)
//             {
//                 int sum = arr[i] + arr[left] + arr[right];

//                 if (sum < target)
//                 {
//                     left++;
//                 }
//                 else if (sum > target)
//                 {
//                     right--;
//                 }
//                 else
//                 {
//                     // If left and right values are same
//                     if (arr[left] == arr[right])
//                     {
//                         long long len = right - left + 1;
//                         count += len * (len - 1) / 2;
//                         break;
//                     }
//                     else
//                     {
//                         long long lcount = 1, rcount = 1;

//                         while (left + 1 < right && arr[left] == arr[left + 1])
//                         {
//                             lcount++;
//                             left++;
//                         }
//                         while (right - 1 > left && arr[right] == arr[right - 1])
//                         {
//                             rcount++;
//                             right--;
//                         }

//                         count += lcount * rcount;
//                         left++;
//                         right--;
//                     }
//                 }
//             }
//         }
//         return count % MOD;
//     }
// };
// int main()
// {
//     Solution sol;
//     vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
//     int target = 8;
//     cout << sol.threeSumMulti(arr, target) << endl; // Output: 20
//     return 0;
// }
