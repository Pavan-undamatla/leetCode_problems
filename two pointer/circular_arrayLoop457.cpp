#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//  optimized approach

class Solution
{
public:
    int getNext(vector<int> &nums, int i)
    {
        int n = nums.size();
        return (i + nums[i] % n + n) % n;
    }

    bool circularArrayLoop(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {

            int slow = i;
            int fast = i;

            bool forward = nums[i] > 0;

            while (true)
            {

                slow = getNext(nums, slow);
                fast = getNext(nums, fast);

                if ((nums[fast] > 0) != forward)
                    break;

                fast = getNext(nums, fast);

                if ((nums[slow] > 0) != forward ||
                    (nums[fast] > 0) != forward)
                    break;

                if (slow == fast)
                {
                    if (slow == getNext(nums, slow))
                        break; // self-loop
                    return true;
                }
            }
        }
        return false;
    }
};

//  brute force approach

class Solution
{
public:
    bool circularArrayLoop(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {

            vector<bool> visited(n, false);
            int curr = i;
            bool forward = nums[i] > 0;

            while (true)
            {

                if ((nums[curr] > 0) != forward)
                    break;

                if (visited[curr])
                    return true;

                visited[curr] = true;

                int next = (curr + nums[curr] % n + n) % n;

                if (next == curr)
                    break;

                curr = next;
            }
        }

        return false;
    }
};

int main()
{
    vector<int> nums = {2, -1, 1, 2, 2};
    Solution sol;
    bool hasLoop = sol.circularArrayLoop(nums);
    cout << "Does the circular array loop exist? " << (hasLoop ? "Yes" : "No") << endl;
    return 0;
}