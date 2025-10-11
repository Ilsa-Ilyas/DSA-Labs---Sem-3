#include <iostream>
using namespace std;

// Function to check if there exists a subset of array 'a' with sum equal to 'target'
bool subsum(int a[], int size, int target) {
    // Create a 2D dynamic array 's' of size (size+1) x (target+1)
    bool **s = new bool*[size+1];
    for (int i = 0; i <= size; ++i) {
        s[i] = new bool[target+1];
        for (int j = 0; j <= target; ++j)
            s[i][j] = false; 
    }

    // Base case: sum = 0 is always possible (by taking no elements)
    for (int i = 0; i <= size; ++i)
        s[i][0] = true;

    // Fill
    for (int i = 1; i <= size; ++i) {
        for (int sum = 1; sum <= target; ++sum) {
            // If current element is greater than current sum,
            if (a[i-1] > sum)
                s[i][sum] = s[i-1][sum];
            else
                s[i][sum] = s[i-1][sum] || s[i-1][sum - a[i-1]];
        }
    }

    // The answer is stored in s[size][target]
    bool res = s[size][target];

    // Free dynamically allocated memory 
    for (int i = 0; i <= size; ++i)
        delete [] s[i];
    delete [] s;

    return res; 
}

int main() {
    // Input array
    int a[] = {3, 34, 4, 12, 5, 2};
    int size = sizeof(a) / sizeof(a[0]); // Calculate number of elements
    int target = 9; // Target sum to check

    // Call function and print result
    cout << (subsum(a, size, target) ? "True" : "False") << endl;
    return 0;
}
