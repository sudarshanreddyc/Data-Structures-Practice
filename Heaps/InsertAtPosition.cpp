#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
public:
    vector<int> heap;

    // Function to return the parent index
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    // Function to maintain heap property by moving element up
    void heapifyUp(int i)
    {
        while (i > 0 && heap[parent(i)] > heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Function to insert a new element into the heap
    void insert(int value)
    {
        heap.push_back(value);      // Add value at the end
        heapifyUp(heap.size() - 1); // Restore heap property
    }

    // Function to decrease the value of a key at index i
    void decreaseKey(int i, int newValue)
    {
        if (i < 0 || i >= heap.size())
        {
            cout << "Index out of bounds!" << endl;
            return;
        }

        if (newValue > heap[i])
        {
            cout << "New value is greater than the current value!" << endl;
            return;
        }

        heap[i] = newValue; // Set the new value
        heapifyUp(i);       // Restore heap property
    }

    // Function to print the heap
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
    minHeap.insert(15);
    minHeap.insert(30);
    minHeap.insert(40);

    cout << "Heap after insertions: ";
    minHeap.printHeap();

    // Decrease key at index 2 (value 15 → change to 5)
    minHeap.decreaseKey(2, 5);

    cout << "Heap after decreaseKey(2, 5): ";
    minHeap.printHeap();

    return 0;
}