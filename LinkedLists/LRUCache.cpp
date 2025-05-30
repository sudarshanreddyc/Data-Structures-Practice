struct Node
{
    int key, val;
    Node *prev;
    Node *next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
public:
    int x;
    unordered_map<int, Node *> mp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    LRUCache(int capacity)
    {
        x = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (!mp.count(key))
            return -1;
        else
        {
            // Move the current node to the front as it is being used
            Node *node = mp[key];
            deleteNode(node);
            insertAtTheBeginning(node);

            return node->val;
        }
    }

    void put(int key, int value)
    {

        // If already present
        if (mp.count(key))
        {
            Node *node = mp[key];
            // Delete the node from the original position
            deleteNode(node);
            // Insert at the beginning as it is being used
            insertAtTheBeginning(node);
            node->val = value;
        }
        else
        {
            Node *newNode = new Node(key, value);
            // If out of capacity
            if (mp.size() == x)
            {
                // Remove LRU
                Node *lru = tail->prev;
                mp.erase(lru->key);
                deleteNode(lru);
            }
            // Insert at the beginning as it is being used and update the map
            mp[key] = newNode;
            insertAtTheBeginning(newNode);
        }
    }

    void insertAtTheBeginning(Node *node)
    {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    void insertAtTheEnd(Node *node)
    {
        node->next = tail;
        tail->prev->next = node;
        node->prev = tail->prev;
        tail->prev = node;
    }

    void deleteNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(val);
 * obj->put(val,value);
 */