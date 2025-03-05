/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int counter = 0;
        ListNode *slowPtr = head;
        ListNode *fastPtr = head;
        while (counter < n)
        {
            fastPtr = fastPtr->next;
            counter++;
        }
        if (fastPtr == NULL)
            return head->next;
        while (fastPtr->next != NULL)
        {
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }
        slowPtr->next = slowPtr->next->next;
        return head;
    }
};