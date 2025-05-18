/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // unordered_map<Node*, Node*> mp;
        // Node* temp = head;

        // //Create a new node and create a hashmap with old and new nodes
        // while(temp){
        //     Node* newNode = new Node(temp->val);
        //     mp[temp] = newNode;
        //     temp = temp->next;
        // }

        // temp = head;
        // Node* copyNode;
        // //Loop through again and construct next and random pointers.
        // while(temp){
        //     copyNode = mp[temp];
        //     copyNode->next = mp[temp->next];
        //     copyNode->random = mp[temp->random];
        //     temp = temp->next;
        // }

        // return mp[head];

        // Place copy nodes in between each node
        Node *temp = head;
        while (temp)
        {
            Node *newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        temp = head;
        if (!temp)
            return temp;
        while (temp)
        {
            Node *newNode = temp->next;
            newNode->random = temp->random == NULL ? NULL : temp->random->next;
            temp = newNode->next;
        }
        temp = head;
        Node *newHead = temp->next;

        // Create a new List from the cloned nodes and also remove the links to old and new nodes and keep old nodes as it is.
        while (temp)
        {
            Node *newNode = temp->next;
            temp->next = newNode->next;
            newNode->next = newNode->next ? newNode->next->next : NULL;
            temp = temp->next;
        }
        return newHead;
    }
};