#include <iostream>
using namespace std;

int main() {
    // Initialize an array of 5 integers
    int arr[5] = {10, 20, 30, 40, 50};

    // Loop through the array using its size
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        // Print element index (1-based) and the element value
        cout << "1D array: " << i + 1 << " = " << arr[i] << endl;
    }

    // Print the number of elements in the array
    cout << sizeof(arr) / sizeof(arr[0]) << endl;

    return 0;
}
