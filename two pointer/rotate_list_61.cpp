#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//  optimal solution

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (!head || !head->next || k == 0)
            return head;

        ListNode *temp = head;
        int size = 1;

        // Find size
        while (temp->next)
        {
            temp = temp->next;
            size++;
        }

        k = k % size;
        if (k == 0)
            return head;

        temp->next = head; // Make circular

        ListNode *curr = head;

        for (int i = 1; i < size - k; i++)
        {
            curr = curr->next;
        }

        ListNode *newHead = curr->next;
        curr->next = NULL;

        return newHead;
    }
};

// brute force solution

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (!head || !head->next || k == 0)
            return head;

        while (k--)
        {

            ListNode *prev = NULL;
            ListNode *curr = head;

            // Go to last node
            while (curr->next)
            {
                prev = curr;
                curr = curr->next;
            }

            // Move last node to front
            prev->next = NULL;
            curr->next = head;
            head = curr;
        }

        return head;
    }
};

int main()
{
    Solution s;

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = s.rotateRight(head, 2);
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}