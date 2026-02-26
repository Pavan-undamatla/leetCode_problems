class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        if (head == NULL)
        {
            return 0;
        }
        ListNode *current = head;
        while (current != NULL && current->next != NULL)
        {

            if (current->val == current->next->val)
            {
                ListNode *prev = current->next;
                current->next = prev->next;
                delete prev;
            }
            else
            {
                current = current->next;
            }
        }
        return head;
    }
};