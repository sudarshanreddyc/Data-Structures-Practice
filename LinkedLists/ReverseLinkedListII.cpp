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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;

        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode *prev = dummyNode;
        ListNode *lPtr = head;
        int index = 1;
        while (index != left)
        {
            prev = lPtr;
            lPtr = lPtr->next;
            index++;
        }
        ListNode *cur = lPtr;
        ListNode *next = nullptr;
        ListNode *prevNode = nullptr;
        while (index <= right)
        {
            next = cur->next;
            cur->next = prevNode;
            prevNode = cur;
            cur = next;
            index++;
        }
        lPtr->next = cur;
        prev->next = prevNode;

        return dummyNode->next;
    }
};
