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
    bool isPalindrome(ListNode *head)
    {
        ListNode *slowPtr = head;
        ListNode *fastPtr = head;

        if (!head->next)
            return true;
        while (fastPtr->next && fastPtr->next->next)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        ListNode *current = slowPtr->next;
        ListNode *nextPtr = slowPtr->next;
        ListNode *prev = NULL;
        while (current)
        {
            nextPtr = current->next;
            current->next = prev;
            prev = current;
            current = nextPtr;
        }
        ListNode *firstHalf = head;
        ListNode *secondHalf = prev;
        while (secondHalf)
        {
            if (firstHalf->val != secondHalf->val)
                return false;
            secondHalf = secondHalf->next;
            firstHalf = firstHalf->next;
        }
        return true;
    }
};