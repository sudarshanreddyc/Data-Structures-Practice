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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *nextPtr;
        ListNode *head;

        if (!list1)
            return list2;
        if (!list2)
            return list1;

        // Initialize head
        if (list1->val <= list2->val)
        {
            head = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            list2 = list2->next;
        }

        ListNode *current = head;

        // Merge the lists
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val <= list2->val)
            {
                nextPtr = list1->next;
                current->next = list1; // Attach list1 node to the merged list
                list1 = nextPtr;
            }
            else
            {
                nextPtr = list2->next;
                current->next = list2; // Attach list2 node to the merged list
                list2 = nextPtr;
            }
            current = current->next; // Move to the last node in the merged list
        }

        // Attach the remaining nodes
        if (list1 != NULL)
        {
            current->next = list1;
        }
        else
        {
            current->next = list2;
        }

        return head;
    }
};