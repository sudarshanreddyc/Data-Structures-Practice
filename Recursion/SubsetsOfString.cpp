/******************************************************************************

Problem: Given a string of length n, find all it's subsets.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// Function definition
void generateSubsets(string str, string currentString, int index, vector<string> &result) {
    // Base case: when we reach the end of the string
    if (index == str.length()) {
        result.push_back(currentString);  // Add the current subset to the list
        return;
    }

    // Exclude the current character
    generateSubsets(str, currentString, index + 1, result);

    // Include the current character
    generateSubsets(str, currentString + str[index], index + 1, result);
}

int main() {
    string input = "abc";  // Input string
    vector<string> result; // To store the subsets

    // Call the subsets function
    generateSubsets(input, "", 0, result);

    // Print the subsets
    for (string subset : result) {
        cout << subset << endl;
    }

    return 0;
}