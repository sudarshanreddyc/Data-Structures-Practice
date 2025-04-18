#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
public:
    vector<int> heap;

    void heapifyUp(int i)
    {

        while (i > 0)
        {
            int parentIndex = floor((i - 1) / 2);
            if (heap[parentIndex] > heap[i])
            {
                swap(heap[parentIndex], heap[i]);
                i = parentIndex;
            }
            else
                break;
        }
    }

    void insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);

        printHeap(heap);
    }

    void printHeap(vector<int> heap)
    {
        for (int n : heap)
        {
            cout << n << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    MinHeap minHeap;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        minHeap.insert(value);
    }
}
