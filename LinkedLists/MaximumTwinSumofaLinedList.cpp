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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    int pairSum(ListNode *head)
    {
        ListNode *mid = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            mid = mid->next;
            fast = fast->next->next;
        }

        ListNode *newHead = reverseList(mid);
        int maxSum = INT_MIN;
        while (newHead)
        {
            maxSum = max(maxSum, head->val + newHead->val);
            head = head->next;
            newHead = newHead->next;
        }
        return maxSum;
    }
};