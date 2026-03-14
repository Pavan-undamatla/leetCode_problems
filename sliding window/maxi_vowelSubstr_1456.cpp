#include <iostream>
#include <string>
#include <vector>
using namespace std;

// optimal approach

class Solution
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k)
    {
        int count = 0;
        int max_val = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (isVowel(s[i]))
                count++;

            if (i >= k && isVowel(s[i - k]))
                count--;

            max_val = max(max_val, count);
        }

        return max_val;
    }
};

// better approach

class Solution
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k)
    {
        int max_val = 0;
        int n = s.size();
        int count = 0;

        for (int i = 0; i < k; i++)
        {
            if (isVowel(s[i]))
            {
                count++;
            }
        }
        max_val = count;

        for (int i = k; i < n; i++)
        {
            if (isVowel(s[i]))
            {
                count++;
            }
            if (isVowel(s[i - k]))
            {
                count--;
            }

            max_val = max(max_val, count);
        }
        return max_val;
    }
};

//  brute force approach

class Solution
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k)
    {
        int max_val = 0;
        int n = s.size();

        for (int i = 0; i < n - k; i++)
        {
            int count = 0;
            for (int j = i; j < k + i; j++)
            {
                if (isVowel(s[j]))
                {
                    count++;
                }
            }
            max_val = max(max_val, count);
        }
        return max_val;
    }
};

int main()
{
    Solution s;
    string str = "abciiidef";
    int k = 3;
    cout << s.maxVowels(str, k);
    return 0;
}
