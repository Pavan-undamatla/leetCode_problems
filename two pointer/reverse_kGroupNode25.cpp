#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//  optimized approach
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || k == 1)
        {
            return head;
        }
        ListNode *first = head;
        for (int i = 0; i < k; i++)
        {
            if (first == NULL)
            {
                return head;
            }
            first = first->next;
        }

        ListNode *curr = head;
        ListNode *prev = NULL;
        while (curr != first)
        {
            ListNode *Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        head->next = reverseKGroup(first, k);
        return prev;
    }
};

//  brute force approach
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || k == 1)
        {
            return head;
        }
        vector<ListNode *> nodes;
        ListNode *current = head;
        while (current != NULL)
        {
            nodes.push_back(current);
            current = current->next;
        }
        int n = nodes.size();
        for (int i = 0; i + k <= n; i += k)
        {

            reverse(nodes.begin() + i, nodes.begin() + i + k);
        }

        for (int i = 0; i < n - 1; i++)
        {

            nodes[i]->next = nodes[i + 1];
        }
        nodes[n - 1]->next = NULL;
        return nodes[0];
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
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next->next->next->next = new ListNode(9);

    int k = 3;

    head = s.reverseKGroup(head, k); // ⚠ IMPORTANT

    // Print list
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}