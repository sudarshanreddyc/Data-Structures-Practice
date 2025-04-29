class SmallestInfiniteSet
{
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    set<int> removed;

public:
    SmallestInfiniteSet()
    {
        for (int i = 1; i <= 100000; ++i)
        { // Choosing a large number as an approximation
            minHeap.push(i);
        }
    }

    int popSmallest()
    {
        int num = minHeap.top();
        minHeap.pop();
        removed.insert(num);
        return num;
    }

    void addBack(int num)
    {
        if (removed.find(num) != removed.end())
        {
            minHeap.push(num);
            removed.erase(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */