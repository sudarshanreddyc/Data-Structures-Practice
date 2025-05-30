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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *prev, *cur;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        prev = dummy;
        cur = head;
        bool duplicatesFound = false;
        while (cur)
        {
            if (cur->next != nullptr && cur->val == cur->next->val)
            {

                // There can be more duplicates, go till end
                while (cur->next && cur->val == cur->next->val)
                {
                    cur = cur->next;
                }
                prev->next = cur->next;
            }
            else
                prev = cur;

            cur = cur->next;
        }
        return dummy->next;
    }
};