#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
public:
    vector<int> heap;

    // Get parent, left, right child indices
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Heapify down (fix heap property after deletion)
    void heapifyDown(int i)
    {
        int smallest = i;
        int l = left(i), r = right(i);

        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // Heapify up (fix heap property after updating a value)
    void heapifyUp(int i)
    {
        while (i > 0 && heap[parent(i)] > heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Insert a new element into the heap
    void insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Delete an element at a specific index
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= heap.size())
        {
            cout << "Invalid index!" << endl;
            return;
        }

        // Replace element at index with last element
        heap[index] = heap.back();
        heap.pop_back();

        // Fix heap property based on new value at index
        // - If the new value is smaller than its parent, apply heapify-up.
        // - Otherwise, if the new value is larger than its children, apply heapify-down.
        if (index > 0 && heap[index] < heap[parent(index)])
        {
            heapifyUp(index);
        }
        else
        {
            heapifyDown(index);
        }

        // Print updated heap
        printHeap();
    }

    // Print heap elements
    void printHeap()
    {
        for (int num : heap)
            cout << num << " ";
        cout << endl;
    }
};

int main()
{
    MinHeap minHeap;

    // Insert some elements
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(30);
    minHeap.insert(40);

    cout << "Heap after insertions: ";
    minHeap.printHeap();

    // Delete element at index 2
    cout << "Heap after deleting index 2: ";
    minHeap.deleteAtIndex(2);

    return 0;
}