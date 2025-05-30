/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        // if(!root) return root;

        // queue<Node*> q;
        // q.push(root);
        // while(!q.empty()){
        //     int size = q.size();
        //     Node* dummy = new Node(-1);
        //     while(size-- > 0){
        //         Node* node = q.front();
        //         dummy->next = node;
        //         dummy = dummy->next;
        //         q.pop();
        //         if(node->left) q.push(node->left);
        //         if(node->right) q.push(node->right);
        //     }
        // }
        // return root;

        if (!root)
            return root;

        Node *cur = root;

        while (cur)
        {
            Node *dummy = new Node(-1);
            dummy->next = nullptr; // If no other level is present, it's next will be null. We are setting it after while loop
            Node *temp = dummy;
            while (cur)
            {
                if (cur->left)
                {
                    temp->next = cur->left;
                    temp = temp->next;
                }
                if (cur->right)
                {
                    temp->next = cur->right;
                    temp = temp->next;
                }
                cur = cur->next;
            }
            cur = dummy->next; // Next level
        }
        return root;
    }
};