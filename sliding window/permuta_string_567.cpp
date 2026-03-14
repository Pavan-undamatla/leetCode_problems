#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// optimal approach

class Solution
{

public:
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.size();
        int n = s2.size();

        if (m > n)
            return false;

        vector<int> freqs1(26, 0);
        vector<int> freqs2(26, 0);

        for (char c : s1)
        {

            freqs1[c - 'a']++;
        }
        for (int j = 0; j < n; j++)
        {
            freqs2[s2[j] - 'a']++;

            if (j >= m)
            {
                freqs2[s2[j - m] - 'a']--;
            }
            if (freqs1 == freqs2)
            {
                return true;
            }
        }
        return false;
    }
};

// brute force approach

class Solution
{

public:
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.size();
        int n = s2.size();

        if (m > n)
            return false;

        vector<int> freqs1(26, 0);

        for (char c : s1)
            freqs1[c - 'a']++;

        for (int i = 0; i <= n - m; i++)
        {
            vector<int> freqs2(26, 0);

            for (int j = i; j < i + m; j++)
                freqs2[s2[j] - 'a']++;

            if (freqs1 == freqs2)
                return true;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    string s1 = "ab";
    string s2 = "eidbooa";
    cout << sol.checkInclusion(s1, s2);
}