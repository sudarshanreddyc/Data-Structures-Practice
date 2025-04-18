#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
public:
    vector<int> heap;

    // Get left child index
    int left(int i) { return 2 * i + 1; }
    // Get right child index
    int right(int i) { return 2 * i + 2; }
    // Get parent index
    int parent(int i) { return (i - 1) / 2; }

    // Function to maintain heap property by moving element up
    void heapifyUp(int i)
    {
        while (i > 0 && heap[parent(i)] > heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Function to maintain heap property by moving element down
    void heapifyDown(int i)
    {
        int smallest = i;
        int l = left(i), r = right(i);

        if (l < heap.size() && heap[l] < heap[smallest])
        {
            smallest = l;
        }
        if (r < heap.size() && heap[r] < heap[smallest])
        {
            smallest = r;
        }

        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // Insert a new element into the heap
    void insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
        printHeap();
    }

    // Delete the minimum element (root)
    void deleteMin()
    {
        if (heap.empty())
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        // Replace root with last element & remove last
        heap[0] = heap.back();
        heap.pop_back();

        // Restore heap property
        heapifyDown(0);
        printHeap();
    }

    // Print the heap
    void printHeap()
    {
        for (int num : heap)
        {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main()
{
    MinHeap minHeap;

    // Insert elements
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(30);
    minHeap.insert(40);

    cout << "Heap after insertions:" << endl;
    minHeap.printHeap();

    // Delete min (root)
    cout << "Heap after deleting min:" << endl;
    minHeap.deleteMin();

    return 0;
}