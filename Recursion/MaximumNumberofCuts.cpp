/******************************************************************************

Problem: Maximum Number of Cuts
You are given a rod of length n and you want to cut it into smaller pieces. You are provided three possible lengths: a, b, and c. Your task is to find the maximum number of pieces that you can obtain by cutting the rod into segments of these lengths. Each segment must be of length a, b, or c.

If it is not possible to cut the rod into pieces of exactly these lengths, return -1.

Input:
An integer n representing the length of the rod.
Three integers a, b, and c representing the lengths of the segments you can cut.
Output:
Return the maximum number of pieces the rod can be cut into, or -1 if it is not possible to cut the rod exactly.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int maxCuts(int n, int a, int b, int c){
    if(n == 0) return 0;
    if(n < 0) return -1;
    
    // Recursively call maxCuts to explore all possibilities
    int resultA = maxCuts(n - a, a, b, c);
    int resultB = maxCuts(n - b, a, b, c);
    int resultC = maxCuts(n - c, a, b, c);
    
    // Find the maximum among the three results
    int result = max({resultA, resultB, resultC});
    
    if (result == -1) return -1;  // If no valid cuts are found, return -1
    return result + 1;  // Add 1 to include the current cut
}

int main()
{
    cout<<maxCuts(5, 2, 1, 5);

    return 0;
}