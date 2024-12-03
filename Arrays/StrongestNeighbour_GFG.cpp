// CPP code to find maximum of
// all subarray of size two
#include <iostream>
#include <climits>
using namespace std;

void maximumAdjacent(int, int[]);

// Function to find maximum for every adjacent pairs in the array.
void maximumAdjacent(int sizeOfArray, int arr[])
{

    for (int i = 0; i < sizeOfArray - 1; i++)
    {
        if (arr[i] >= arr[i + 1])
            cout << arr[i] << " ";
        else
            cout << arr[i + 1] << " ";
    }
}

// Driver Code
int main()
{

    // Testcase input
    int testcases;
    cin >> testcases;

    // Looping through all testcases
    while (testcases--)
    {
        int sizeOfArray;
        cin >> sizeOfArray;

        int arr[sizeOfArray];

        // Array input
        for (int index = 0; index < sizeOfArray; index++)
        {
            cin >> arr[index];
        }

        maximumAdjacent(sizeOfArray, arr);
        cout << endl;

        cout << "~" << "\n";
    }

    return 0;
}