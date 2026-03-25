#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// optimal approach

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        while (temp != NULL)
        {

            if (temp->next != NULL && temp->val == temp->next->val)
            {
                while (temp->next != NULL && temp->val == temp->next->val)
                {
                    temp = temp->next;
                }
                prev->next = temp->next;
            }
            else
            {
                prev = prev->next;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};

//  brute force approach

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        unordered_map<int, int> freq;

        ListNode *temp = head;
        while (temp != NULL)
        {
            freq[temp->val]++;
            temp = temp->next;
        }

        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        ListNode *curr = head;

        while (curr != NULL)
        {

            if (freq[curr->val] == 1)
            {
                prev->next = new ListNode(curr->val);
                prev = prev->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};

int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *temp = head;
    temp->next = new ListNode(2);
    temp = temp->next;
    temp->next = new ListNode(3);
    temp = temp->next;
    temp->next = new ListNode(3);
    temp = temp->next;
    temp->next = new ListNode(4);
    temp = temp->next;
    temp->next = new ListNode(4);
    temp = temp->next;
    temp->next = new ListNode(5);
    head = s.deleteDuplicates(head);

    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}