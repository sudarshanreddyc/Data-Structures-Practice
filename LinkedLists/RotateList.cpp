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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return head;

        ListNode *tail = head;
        int len = 1;

        // Find len and tail at the same time
        while (tail->next)
        {
            len++;
            tail = tail->next;
        }

        if (k % len == 0)
            return head;

        tail->next = head;
        int i = 1;
        ListNode *cur = head;
        while (i < len - (k % len))
        { // Move len - k positions foward
            cur = cur->next;
            i++;
        }
        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};